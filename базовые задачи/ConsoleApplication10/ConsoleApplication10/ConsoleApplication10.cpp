// ConsoleApplication10.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include <iostream>
#include <iomanip>


using namespace std;
int main()
{
	setlocale(LC_ALL, "rus"); // ������� �����������
	int a[10]; // ��� ����� ��� �������� ������������ ������
	int b[10]; // ���� ������ �������� ��� ��������������� ������ �� ������� 

	int n; // �� ����� ��� ����� �����
	cout << "����� ����������� �������\n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "������: \n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "x^" << i << setw(5);
	}
	// �� ����� ������� �� �����
	cout << endl;
	for (int i = 0; i <=n; i++)
	{
		b[i] = a[i];// ���������� ����������� ������� ����� 
	}
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " " << endl;
	}
	// ����� ��� ��� �������� ����� �������� ���� (x-q), q �� ������ 
	cout << "������� �������� ";
	int q;
	cin >> q;
	cout << "x+" << q << endl;


	// ��� ����  ������� ������� ����� �� ����� �������
	for (int i = 1; i < n-1;i++)
	{
		b[n-i-1] = q*b[n-i] + a[n-i-1];
	}
		b[0] = q*b[1] + a[0];

		//������� �� ��� ���������

	for (int i = 0; i < n; i++)
	{

		cout << b[i]<< " ";

	}

	// � ��� ����� �������� ��� �������� � ���������� ���� ����������
	cout << endl;
	cout << "/: " << endl;
	cout << "(x+" << q << ")" << "(";
	for (int i = 1; i < n-1; i++)
	{
		cout << b[n - i] << "*x^" << n - i - 1 << "+";

	}
	cout << b[1] << "+" << ")" << b[0];

	system("pause");

    return 0;
}

