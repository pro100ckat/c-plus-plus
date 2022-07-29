#pragma once
#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include "math.h"

using namespace std;

class dm
{
public:
	dm(int k = 0, int y = 0);
	dm(const dm& x);
	dm(int k, int* x);
	~dm();
	int search(const int key);
	void add(int key, int k = -1);
	void del(int index);
	int getN();
	int* getA();
	const dm &operator= (const dm & a);
	friend int operator* (const dm &left, const dm &right);
	friend dm operator+ (const dm &left, const dm &right);
	friend ostream &operator<< (ostream &output, const dm & x);
	friend istream &operator >> (istream & input, dm &x);
	friend const dm& operator++(dm& arr);	//префиксный инкремент
	friend const dm operator++(dm& arr, int); 	//постфиксный инкремент
private:
	int *a;
	int n;
};

double abs(dm &a) {
	double result = 0;
	int n = a.getN();
	int *arr = a.getA();
	for (int i = 0; i < n; i++)
	{
		result += arr[i] * arr[i];
	}
	result = sqrt(result);
	return result;
}

const dm& operator++(dm& arr) {
	for (int i = 0; i < arr.n; i++)
	{
		arr.a[i]++;
	}
	return arr;
}

const dm operator++(dm& arr, int) {
	dm oldValue(arr);
	for (int i = 0; i < arr.n; i++)
	{
		arr.a[i]++;
	}
	return oldValue;
}

int operator* (const dm &left, const dm &right) {
	if (left.n != right.n)
	{
		cout << "Массивы разного размера!\n";
		exit(1); // завершить работу программы
	}
	int result = 0;
	for (int i = 0; i < left.n; i++)
	{
		result += left.a[i] * right.a[i];
	}
	return result;
}

int* dm::getA() {
	return a;
}

int dm::getN() {
	return n;
}

dm operator+ (const dm &left, const dm &right)
{
	if (left.n != right.n)
	{
		cout << "Массивы разного размера!\n";
		exit(1); // завершить работу программы
	}

	dm result(left.n);
	for (int i = 0; i < left.n; i++)
		result.a[i] = left.a[i] + right.a[i];
	return result;
}
dm::dm(int k, int y)
{
	cout << "constr\n";
	if (k > 0)
	{
		n = k;
		a = new int[k];
		for (int i = 0; i < k; i++)
		{
			a[i] = y;
		}
	}
	else {
		k = y = 0;
		a = NULL;
	}
}

dm::dm(const dm & x) :n(x.n)
{
	cout << "copy const\n";
	a = new int[n];

	for (int i = 0; i < n; i++)
		a[i] = x.a[i];
}

dm::dm(int k, int * x)
{
	cout << "const\n";
	if (k > 0)
	{
		n = k;
		a = new int[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = x[i];
		}
	}
	else
	{
		n = 0;
		a = NULL;
	}
}

dm::~dm()
{
	cout << "destr\n";
	if (!a)delete[] a;
}

int dm::search(const int key)
{
	int cout = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
		{
			cout += 1;
		}
	}
	return cout;
}

void dm::add(int key, int k)
{
	if (k == -1)
	{
		int * result = new int[n + 1];
		for (int i = 0; i < n; i++)
		{
			result[i] = a[i];
		}
		if (a != NULL)
		{
			delete[] a;
		}
		n = n + 1;
		a = result;
		a[n - 1] = key;
	}
	else
	{
		if (k > 0)
		{
			int * result = new int[n + 1];
			for (int i = 0; i < k - 1; i++)
			{
				result[i] = a[i];
			}
			result[k - 1] = key;
			n = n + 1;
			for (int i = k - 1; i < n; i++)
			{
				result[i + 1] = a[i];
			}
			if (a != NULL)
			{
				delete[] a;
			}
			a = result;
		}
	}
}

void dm::del(int index)
{
	if ((index > 0) & (index < n))
	{
		int * result = new int[n - 1];
		for (int i = 0; i < index - 1; i++)
		{
			result[i] = a[i];
		}
		n = n - 1;
		for (int i = index - 1; i < n; i++)
		{
			result[i] = a[i + 1];
		}
		if (a != NULL)
		{
			delete[] a;
		}
		a = result;
	}
}

const dm & dm::operator=(const dm & x)
{
	if (&x != this)
	{
		if (n != x.n)
		{
			delete[] a;
			n = x.n;
			a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = x.a[i];
		}
	}
	return *this;
}

istream &operator >> (istream & input, dm &x)
{
	cout << "Ввод массива ";
	for (int i = 0; i < x.n; i++)
		input >> x.a[i];
	return input;
}

ostream & operator<<(ostream &output, const dm & x)
{
	if (x.a != NULL)
	{
		for (int i = 0; i < x.n; i++) {
			output << "| " << x.a[i];
		}
	}
	else {
		output << "NULL";
	}
	output << "\n";
	return output;
}