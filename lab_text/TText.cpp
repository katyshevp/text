#include "TText.h"
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void gotoxy(int x, int y)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)return;

	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(Console, pos);
}

void clrscr(void)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console) return;

	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(Console, &buf);

	DWORD Count;

	COORD zpos;
	zpos.X = 0;
	zpos.Y = 0;

	FillConsoleOutputCharacter(Console, ' ', buf.dwSize.X * buf.dwSize.Y, zpos, &Count);
	SetConsoleCursorPosition(Console, zpos);
}

void clreol(void)
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)return;

	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(Console, &buf);

	WORD Attr;
	DWORD Count;

	COORD zpos = buf.dwCursorPosition;

	zpos.X = buf.dwCursorPosition.X + 1;
	zpos.Y = buf.dwCursorPosition.Y;

	FillConsoleOutputCharacter(Console, ' ', buf.dwSize.X - buf.dwCursorPosition.X - 1, zpos, &Count);
	SetConsoleCursorPosition(Console, buf.dwCursorPosition);
}



TText::TText(TTextLink *p)
{
	if (p != NULL)pFirst = p;
	else pFirst = new TTextLink();
	pCurr = pFirst;
}

void TText::GoNextLink() {
	if (pCurr != NULL)
	{
		if (pCurr->pNext != NULL)
		{
			steck.Push(pCurr);
			pCurr = pCurr->pNext;
		}
	}
	else throw(-1);
}

void TText::GoDownLink() {
	if (pCurr != NULL)
	{
		if (pCurr->pNext != NULL)
		{
			steck.Push(pCurr);
			pCurr = pCurr->pDown;
		}
	}
	else throw(-1);
}

void TText::GoPrevLink() {
	if (!steck.IsEmpty())
		pCurr = steck.Pop();
}

void TText::GoFirstLink() {
	steck.clear();
	pCurr = pFirst;
}

string TText::GetStr() {
	if (pCurr == NULL)return string(" ");
	else return string(pCurr->str);
}

void TText::SetStr(string &s) {
	if (pCurr != NULL)strcpy(pCurr->str, s.c_str());
}
