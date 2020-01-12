#ifndef KNUTHMORRISPRAT_H
#define KNUTHMORRISPRAT_H

#include <stdio.h>

int  KnuthMorrisPratt(char* szText, int nTextlen, int nStart, char* szPattern, int nPatternLen);

void Preprocess(char* szPattern, int nPatternLen, int* Border);

void printBorder(int* p, int size);

#endif