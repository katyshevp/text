#pragma once
#include <string.h>


const int MaxLen = 81;
class TTextLink {
public:
	char str[MaxLen];
	TTextLink *pNext, *pDown;
	TTextLink(char *n = NULL, TTextLink *pN = NULL, TTextLink *pD = NULL)
	{
		pNext = pN;
		pDown = pD;
		if (n == NULL)str[0] = '\0';
		else strncpy(str, n, 80);
	}
};