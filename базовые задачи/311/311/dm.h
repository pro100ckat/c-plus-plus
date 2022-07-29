#pragma once 
#include "stdafx.h" 
#include <iostream> 
#include "conio.h" 

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
	const dm &operator= (const dm & a);
	friend dm operator+ (const dm &left, const dm &right);
	friend ostream &operator<<(ostream &output, const dm & x);
	friend istream &operator >> (istream & input, dm &x);
private:
	int *a;
	int n;
};
dm operator+ (const dm &left, const dm &right)
{
	return left;
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
	a = new int[n]; // ???????? ????? ? ?????? ??? ??????? 

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
	cout << "???? ??????? ";
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