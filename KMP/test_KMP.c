#include <stdio.h>
#include <string.h>
#include <time.h>

#include "KnuthMorrisPratt.h"

#define MAX_BUFFER 512

int main(int argc, char** argv)
{
	char* szFilePath;
	FILE* fp;

	char  szText[MAX_BUFFER];
	char  szPattern[100];
	int   nPatternLen = 0;
	int   nLineCount = 0;
	int   nPosition;

	clock_t start_time, end_time;

	if (argc < 2)
	{
		printf("Usage: %s <FilePath> <Pattern>\n", argv[0]);
		return 1;
	}

	szFilePath = argv[1];
	//Pattern  = argv[2];
	printf("패턴을 입력하세요 : ");
	gets(szPattern);

	nPatternLen = strlen(szPattern);

	if ((fp = fopen(szFilePath, "r")) == NULL)
	{
		printf("Cannot open file:%s\n", szFilePath);
		return 1;
	}

	start_time = clock();

	while (fgets(szText, MAX_BUFFER, fp) != NULL)
	{
		nPosition = KnuthMorrisPratt(szText, strlen(szText), 0, szPattern, nPatternLen);

		if (nPosition >= 0)
		{
			nLineCount++;
			printf("line:%d, column:%d : %s", nLineCount, nPosition + 1, szText);
		}
	}

	end_time = clock();

	printf("===========================================\n");
	printf("  Total lines : %d\n", nLineCount);
	printf("  Search time : %d ms\n", end_time - start_time);
	printf("===========================================\n");

	return 0;
}