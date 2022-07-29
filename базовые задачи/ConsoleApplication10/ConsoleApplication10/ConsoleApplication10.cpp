// ConsoleApplication10.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include <iostream>
#include <iomanip>


using namespace std;
int main()
{
	setlocale(LC_ALL, "rus"); // русска€ локализаци€
	int a[10]; // это бдует наш исходный динамический массив
	int b[10]; // этот массив создадим как вспомогательный такого же размера 

	int n; // не нужно дл€ нашей проги
	cout << "¬веди размерность массива\n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "ћассив: \n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "x^" << i << setw(5);
	}
	// до этого момента не нужно
	cout << endl;
	for (int i = 0; i <=n; i++)
	{
		b[i] = a[i];// необхожимо скопировать массивы будет 
	}
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << " " << endl;
	}
	// здесь как она говорила будет делитель вида (x-q), q мы вводим 
	cout << "¬ведите делитель ";
	int q;
	cin >> q;
	cout << "x+" << q << endl;


	// —ам цикл  который считает делит по схеме √орнера
	for (int i = 1; i < n-1;i++)
	{
		b[n-i-1] = q*b[n-i] + a[n-i-1];
	}
		b[0] = q*b[1] + a[0];

		//выводим то что получилсь

	for (int i = 0; i < n; i++)
	{

		cout << b[i]<< " ";

	}

	// ј это чтобы записать все подсчеты в нормальном виде многочлена
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

