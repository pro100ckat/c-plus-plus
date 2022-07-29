#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string swap(string s);

int main()
{
	setlocale(LC_ALL, "rus");

	string buff;

	ifstream f1; // открыли файл на чтение
	f1.open("begin.txt");
	
	ofstream f; // открыли файл на запись
	f.open("end.txt");
	
	while (!f1.eof())
	{
		getline(f1,buff);
		cout << buff << endl;
		cout << swap(buff) << " swap" << "\n";
		f << swap(buff) << "\n";
	}
	

	
	f.close();

	f1.close();

	return 0;
}

string swap(string s) {
	string word = "";
	string str = "";
	string::iterator is;
	int max = 0;
	for (is = s.begin(); is != s.end(); is++)
	{
		if (*is != ' ')
		{
			word += *is;
		}
		else if (*is == ' ')
		{
			string::const_iterator it(word.begin()), end(word.end());
			for (; it != end; ++it)
				if (!isdigit(*it)) break;

			if (it == end)
			{
				if (atoi(word.c_str()) > max) max = stoi(word); //atoi(word.c_str());// stoi(s);
			}
			word = "";
		}
	}
	for (is = s.begin(); is != s.end(); is++)
	{
		if (*is != ' ')
		{
			word += *is;
		}
		else if (*is == ' ')
		{
			string::const_iterator it(word.begin()), end(word.end());

			for (; it != end; ++it)
				if (!isdigit(*it)) break;

			if (it == end)
			{
				str += to_string(max) + " ";
				word = "";
				continue;
			}
			str += word + " ";
			word = "";
		}
	}	
	return str;
}