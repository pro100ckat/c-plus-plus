// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"

int summ(int*a, int);
int summ(int **a, int,int );
using namespace std;


int main()

{
	int n;
	int m;
	cout << "Vvedi razmernost \n";
	cin >> n;
	int *array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
		cout << "\n";
	cout << "summ = " << summ(array, n) << endl << "\n";



	cout << "Vvedi 2 m ";
	cin >> n;
	cin >> m;
	int **arr2 = new int *[n];
	for (int i = 0; i < n; i++)  arr2[i] = new int[m];



		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) cin >> arr2[i][j];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) cout << arr2[i][j] << " \n";

		}
	cout << "summ = " << summ(arr2, n, m) << endl;

	for (int i = 0;i<n;i++)
		delete arr2[i];
	delete[] array;
	system("pause");
    return 0;
}

	int summ(int *array, int n)
	{
		int s=0;
		for (int i = 0; i < n; i++)

			s+=array[i];
			return s;
	}
	int summ(int **array, int n, int m)
	{
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				s += array[i][j];
			}
			return s; 
		}

	}
