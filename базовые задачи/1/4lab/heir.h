#pragma once
#include "C:\Users\user\Documents\Visual Studio 2015\Projects\4lab\4lab\dm2.h"

class heir : public dm
{
public:
	heir(int k = 0, int y = 0) : dm(k,y) {}; // �� ���-�� ���������
	heir(const heir& x) : dm(x) {};     // �����������
	heir(int k, int* x) : dm(k, x) {}; // �� ���-�� ��������� � �������
	~heir();
	const heir &operator=(const heir & a) : dm(a) {}; // ���������� =
	friend heir operator+(const heir &left, const heir &right) : dm(left, rigth) {};// ��������
	friend int operator*(const heir &left, const heir &right) : dm(left, rigth) {};	// ������������
	friend heir operator-(const heir &left, const heir &right) : dm(left, rigth) {};	// ���������
	friend ostream &operator << (ostream &output, const heir & x) : dm(output, x) {};
	friend istream &operator >> (istream & input, heir &x);
private:

};

heir::~heir()
{
	cout << "destr B\n";
}