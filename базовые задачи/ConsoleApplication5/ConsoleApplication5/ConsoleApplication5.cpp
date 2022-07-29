// ConsoleApplication5.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "conio.h"
#include "stdio.h"
#include "iostream"
#include "math.h"
#include "stddef.h"

using namespace std;

class dm
{
	friend istream &operator>> (istream &, dm &); // ������������� �������� �����
	friend ostream &operator<< (ostream &, const dm &); // ������������� �������� ������
private:
	int *a;
	int n;
public:
		//dm(); //����������� �� ���������
		dm ( const dm& x); //����������� �����������
		~dm(); //����������
		dm(int k = 0, int y = 0); // ����� � ������� �������
		dm(int k, int *x); // ���������� �� ������
		dm & operator = (const dm&x);
		void getarray();
		void setarray();
		int getSize() const; // ���������� ���������� ��������� �������
		int *getptr()
		{
			return a;
		}
		int getN()
		{
			return n;
		}
};

dm::dm(int k, int y)
{
	cout << "�����������\n ";
	//if (n == 0) a = nullptr;
	if (n == 0) {
		n = 10; // �� ��������� ������ ������� = 10 ���������
		a = new int[n]; // �������� ����� � ������ ��� �������
		for (int i = 0; i < n; i++) // �������� ������
			a[i] = 5;

	}
	else
	{
		n = k;
		a = new int[n];
		for (int i = 0; i < k;i++)
		{
			a[i] = y;

		}

	}

}





int dm::getSize() const // ���������� ���������� ��������� �������
{
	return n;
}





dm::dm(int k, int *x)
{
	int i;
	cout << "�����������\n ";
	if (k > 0)
	{
		n = k;
		a = new int [n];
		for (int i = 0; i < k; i++)
			a[i] = x[i];
	}
	else
	{
		n = 0;
		a = nullptr;

	}
}




dm::~dm() // ����������� ������ Array
{
	delete[] a; // ���������� ������, ������ ������
}




void dm::getarray() // ����� �������
{
	for (int i = 0; i < n; i++)
		cout << " " << a[i]; // ����� ��������� ������� �� �����

	cout << std::endl; // ����� ������
}



void dm::setarray() // ���������� �������
{
	for (int i = 0; i < n; i++)
		cin >> a[i]; // ���� �������� ������� � ����������
}





//dm::dm() // ����������� �� ���������, ��� ����������
//{
//	n = 10; // �� ��������� ������ ������� = 10 ���������
//	a = new int[n]; // �������� ����� � ������ ��� �������
//	for (int i = 0; i < n; i++) // �������� ������
//		a[i] = 5;
//}

// ������������� �������� �����, ��� ����� �������� ������� � ����������
istream &operator>> (istream & input, dm &obj)
{
	for (int i = 0; i < obj.n; i++)
		input >> obj.a[i]; // ��������� ������ ������� obj
	return input; // ��������� ������������� ����, ���� cin >> x >> y >> z >> ...
}

// ������������� �������� ������ ��� ������ Array (����� ��������� ������� �� �����)
ostream &operator<< (ostream &output, const dm &obj)
{
	for (int i = 0; i < obj.n; i++)
	{
		output << "  " // ��� ������ ����� ���������� 5 �������
			<< obj.a[i];
	}

	output << std::endl; // ������� ������� �� ����� ������

	return output; // ��������� ������������� �����, ���� cout << x << y << z << ...
}


int main()
{
	setlocale(LC_ALL, "rus");
	dm myArray1;     // 10-�� ���������� ������ ������ Array, �� ���������
	dm myArray2(15,5); // 15-�� ���������� ������ ������ Array

	cout << "������ ������� myArray1: " << myArray1.getSize() << endl;
	cout << "�������� ������� myArray1, ����� ��� ��������:\n";
	myArray1.getarray(); // ����� ��������� ������� � ������� ������ ������ Array

	cout << "������ ������� myArray2: " << myArray2.getSize() << endl;
	cout << "�������� ������� myArray2, ����� ��� ��������:\n";
	cout << myArray2; // ����� ��������� ������� � ������� �������������� ��������� ������

	cout << "������� 10 �����: ";
	myArray1.setarray(); // ���������� ������� � ������� ������ ������ Array

						 // ��������� ������
	cout << "��������� ������: " << myArray1;

	cout << "������� 15 �����: ";
	cin >> myArray2; // ���������� ������� � ������� �������������� ��������� �����

					 // ��������� ������
	cout << "��������� ������: " << myArray2;

	system("pause");
    return 0;
}

