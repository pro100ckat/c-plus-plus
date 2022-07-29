#include "stdafx.h"
#include "stdio.h" 
#include "conio.h" 
#include <iostream> 
#include <string> 
#include <ctime> //Â <ctime> ñîäåðæèòñÿ time() 
#include <cstdlib> // Ñîäåðæèòò srand() è rand() 

using namespace std;

int wod(int *&a, int n = 3);
int wod(int **&a, int n = 3);
void disp(int *a, int n = 3);
void disp(int **a, int n = 3);
int summ(int a, int b);
int summ(int *a, int *b, int *&c, int n = 3);
int summ(int **a, int **b, int **&c, int n = 3);
void del(int *a);
void del(int **a, int n = 3);

int main() {
	srand(time(0));
	int a1, a2, *b1, *b2, *b3, **c1, **c2, **c3;
	cin >> a1 >> a2;
	cout << a1 << " + " << a2 << " = " << summ(a1, a2) << endl;
	wod(b1);
	wod(b2);
	wod(c1);
	wod(c2);
	disp(b1);
	disp(b2);
	disp(c1);
	disp(c2);
	system("pause");
	summ(b1, b2, b3);
	summ(c1, c2, c3);
	disp(b3);
	disp(c3);
	system("pause");
	del(b1);
	del(b2);
	del(b3);
	del(c1, 3);
	del(c2, 3);
	del(c3, 3);
	return 0;
}

int wod(int *&a, int n) {
	a = new int[n];
	for (int i = 0; i< n; i++)
		a[i] = rand() % 10 + 1;
	//cin » a[i]; 
	return 0;
}

int wod(int **&a, int n) {
	a = new int *[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10 + 1;
			//cin » a[i][j]; 
		}
	}
	return 0;
}

void disp(int *a, int n) {
	for (int i = 0; i< n; i++)
	{
		cout << "|" << a[i];
	}
	cout << endl;
	cout << endl;
}

void disp(int **a, int n) {
	int i;
	int j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "|" << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}


int summ(int a, int b) {
	int c;
	return c = a + b;
}

int summ(int *a, int *b, int *&c, int n) {
	c = new int[n];
	for (int i = 0; i < n; i++) {
		c[i] = a[i] + b[i];
	}
	return 0;
}

int summ(int **a, int **b, int **&c, int n) {
	c = new int*[n];
	for (int i = 0; i < n; i++) {
		c[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	return 0;
}

void del(int *a) {
	if (a != 0)
	{
		delete[]a;
	}
}

void del(int **a, int n) {
	for (int i = 0; i < n; i++)
	{
		delete[]a[i];
	}
	delete[]a;
}