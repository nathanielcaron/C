#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef GETWORDSTATS_H
#define GETWORDSTATS_H

void getWordStats(char *word, FILE *f, int *sum, int *num);

//Function template for strlwr
char *strlwr(char *str);

#endif