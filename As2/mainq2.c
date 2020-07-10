/*
 * Assignment 2
 * Question 2
 * Nathaniel Caron
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getWordStats.h"

int main(int argc, char **argv) {

    // Get the user input
    printf("Enter a review:\n");
    char review[1000] = {0};
    char current = NULL;
    int count = 0;

    current = (char)fgetc(stdin);
    while (current != '\n') {
        review[count] = current;
        count++;
        current = (char)fgetc(stdin);
    }

    // Open the file movieReviews.txt in read mode
    FILE *f = fopen(argv[1], "r");

    if (f == NULL) {
        perror("ERROR: ");
        return EXIT_FAILURE;
    }

    // Initialize variables
    int wordSum = 0;
    int wordNum = 0;
    double reviewSum = 0;
    int reviewNum = 0;
    double reviewAvg = 0;

    // Convert user input to lower case
    char *lowerReview = strlwr(review);

    // Pointer to next token for subsequent strtok calls
    char *rest = lowerReview;

    // Calculate the word values
    for (char *token = strtok(rest, " "); token != NULL; token = strtok(rest, " ")) {

        rest += strlen(token) + 1;

        wordSum = 0;
        wordNum = 0;

        getWordStats(token, f, &wordSum, &wordNum);

        if (wordNum > 0) {
            reviewSum += (double)wordSum/(double)wordNum;
            reviewNum += 1;
        }

        fseek(f, 0, SEEK_SET);
    }

    if (reviewNum > 0) {
        reviewAvg = reviewSum / reviewNum;
    }
    else {
        reviewAvg = 0;
    }



    // Print the results
    printf("The review has an average value of %f.\n", reviewAvg);
    if (reviewAvg >= 2) {
        printf("Positive Sentiment\n");
    }
    else {
        printf("Negative Sentiment\n");
    }

    return EXIT_SUCCESS;
}