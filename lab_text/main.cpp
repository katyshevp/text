#include "TText.h"
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream ifs("Test.txt");
	TText m1;
	char tmp[9];

	m1.Read((char*)("Test.txt"));
	m1.Print();
	m1.WorkWith();
}