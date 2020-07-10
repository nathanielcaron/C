/*
 * Assignment 2
 * Question 1
 * Nathaniel Caron
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getWordStats.h"

int main(int argc, char **argv) {

    // Get the user input
    printf("Enter a word: ");
    char word[256] = {0};
    scanf("%s", word);

    // Open the file movieReviews.txt in read mode
    FILE *f = fopen(argv[1], "r");

    if (f == NULL) {
        perror("ERROR: ");
        return EXIT_FAILURE;
    }

    // Initialize variables
    int sum = 0;
    int num = 0;

    // Convert user input to lower case
    char *lowerWord = strlwr(word);

    // Get the statistics for the word
    getWordStats(lowerWord, f, &sum, &num);

    // Print results
    printf("%s appeared %d times.\n", word, num);
    double avg = 0;
    if (num > 0) {
        avg = ((double)sum / (double)num);
    }
    else {
        avg = 0;
    }

    printf("The average score for reviews containing %s is %f.\n", word, avg);

    return EXIT_SUCCESS;
}