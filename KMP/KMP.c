#include "KnuthMorrisPratt.h"
#include <stdlib.h>

void printBorder(int* p, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", p[i]);
	}

	printf("\n");
}

void Preprocess(char* szPattern, int PatternSize, int* Border)
{
	int i = 0;
	int j = -1;

	Border[0] = -1;
	while (i < PatternSize)
	{
		while (j > -1 &&szPattern[i] != szPattern[j])
			j = Border[j];
		i++;
		j++;

		Border[i] = j;
	}
}

int  KnuthMorrisPratt(char* szText, int nTextlen, int nStart, char* szPattern, int nPatternLen)
{
	int i = nStart;
	int j = 0;
	int Position = -1;

	int* Border = (int*)calloc(nPatternLen + 1, sizeof(int));
	Preprocess(szPattern,nPatternLen, Border);
	while (i <szText)
	{
		while (j >= 0 && szText[i] != szPattern[j])
			j = Border[j];
		i++;
		j++;
		if (j == nPatternLen)
		{
			Position = i - j;
			break;
		}
	}
	free(Border);
	return Position;
}
