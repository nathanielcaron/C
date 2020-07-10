#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "getWordStats.h"

// Function template for strlwr
char *strlwr(char *str);

void getWordStats(char *word, FILE *f, int *sum, int *num) {

    // The current line of text to be read
    char line[500] = {0};
    // The current score on the line being read
    int lineScore = 0;

    while (fgets(line, 500, f) != NULL) {

        for (char *token = strtok(line, " \t"); token != NULL; token = strtok(NULL, " \t")) {

            if ((strcmp(strlwr(token), word)) == 0) {
                // Increment the count
                (*num)++;
                // Grab the score at the beginning of the line
                lineScore = line[0] - '0';
                // Add the score to the sum
                (*sum) += lineScore;
            }

        }
	}

}

char *strlwr(char *str) {

  for (int i = 0; str[i]; i++) {
    str[i] = tolower(str[i]);
  }

  return str;

}