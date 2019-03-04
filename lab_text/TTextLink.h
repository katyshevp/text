#pragma once
#include <string.h>
#include <stdio.h>

using namespace std;

const int Maxlen = 81;
class TTextLink
{
	public:
		char str[Maxlen];
		TTextLink *pNext, *pDown;
		TTextLink(char *s = NULL, TTextLink *pN = NULL, TTextLink *pD = NULL)
		{
			pNext = pN;
			pDown = pD;
			if (s == NULL)
				str[0] = '\0';
			else
				strcpy(str, s);
		}
		~TTextLink()
		{

		}

};