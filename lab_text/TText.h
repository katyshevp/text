#pragma once
#include "stack.h"
#include <string>
#include <fstream>
#include "TTextLink.h"

class TText 
{
	int TL;
	TTextLink *pFirst, *pCurr;
	TStack<TTextLink*> steck;
public:
	void GoNextLink();
	TText(TTextLink *p = NULL);
	void GoPrevLink();
	void GoFirstLink();
	std::string GetStr();
	void SetStr(std::string &s);
	void InsNextSection(std::string &s);
	void InsNextLink(std::string s);
	void InsDownLink(std::string s);
	void InsDownSection(std::string s);
	void GoDownLink();
	void DelNext();
	void DelDown();
	TTextLink* ReadText(std::ifstream &ifs);
	void Read(char *fn);
	void PrintText(TTextLink *tmp);
	void Print();
	void Reset();
	void GoNext();
	bool IsEnd();
	void WorkWith();
	int Obhod(TTextLink *tmp);
};
