#include "stdafx.h"
#include <iostream>
#include <conio.h>


using namespace std;

class Students {
public:
	// ����������
	~Students()
	{
		std::cout << "Memory has been cleaned. Good bye." << std::endl;
	}
};
class Students {
public:
	// ����������� ������ Students
	Students(int default_score)
	{
		for (int i = 0; i < 5; ++i) {
			scores[i] = default_score;
		}
	}

private:
	int scores[5];
};

int main()
{
	Students *student = new Students(2);
	
	// ����������� �������
	delete student;
	_getch();
	return 0;
	

}