#include "KarpRabin.h"
#include <stdio.h>
#include <math.h>

int KarpRabin(char* Text, int TextSize, int Start, char* Pattern, int PatternSize)
{
	int i = 0;
	int j = 0;
	int Coefficient = pow(2.0, PatternSize - 1);

	int HashText = Hash(Text, PatternSize);
	int HashPattern = Hash(Pattern, PatternSize);

	for (i = Start; i <= TextSize - PatternSize; i++)
	{
		HashText = ReHash(Text, i, PatternSize, HashText, Coefficient);

		if (HashPattern == HashText)
		{
			for (j = 0; j < PatternSize; j++)
			{
				if (Text[i + j] != Pattern[j])
					break;
			}

			if (j >= PatternSize)
				return i;
		}
	}

	return -1;
}

int Hash(char* String, int Size)
{
	int i = 0;
	int HashValue = 0;

	for (i = 0; i < Size; i++)
	{
		HashValue += (String[i] * pow(2.0, Size - (1 + i)));
	}

	return HashValue;
}

int ReHash(char* String, int Start, int Size, int HashPrev, int Coefficient)
{
	if (Start == 0)
		return HashPrev;

	return String[Start + Size - 1] + (2 * (HashPrev - Coefficient * String[Start - 1]));
}
