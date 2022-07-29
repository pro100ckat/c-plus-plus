// ласс параллелограмма 
#include "stdafx.h" 
#include <iostream> 
#include <cmath> 
#include "conio.h" 
#include <math.h> 

using namespace std;

class parallel
{
private:
	int a, b; // стороны параллелограмма 
	float x; // угол 
	static int N;

public:
	parallel(); //int a, int b, float x 
	parallel(const parallel& a);
	void setParallel();
	void getParallel();
	int perimetr();
	float area();
	static int getN() { return N; }
	friend ostream& operator<<(ostream& os, const parallel& dat);
	friend istream& operator>>(istream& is, parallel& dat);
	~parallel();
};

int parallel::N = 0;

parallel::parallel()//int a, int b, float x 
{
	a = 0;
	b = 0;
	x = 0;//присвоим начальные значени€ переменным 
		  //и здесь же их отобразим на экран 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	N++;
}

parallel::parallel(const parallel& a)
{
	N++;
	cout << "copy_constr\n";
}

void parallel::setParallel()
{
	cout << "¬ведите стоороны, угол"<< endl;
	cin >> a >> b >> x;
}

void parallel::getParallel()
{
	cout << "a = " << a << " b = " << b << " x = " << x << endl;
}

int parallel::perimetr()
{
	return 2 * (a + b);
}

float parallel::area()
{
	return a*b*sin(x);
}

parallel::~parallel()
{
	cout << "destr\n";
	N--;
}

ostream& operator <<(ostream& out, const parallel& a)
{
	out << a.a << endl;
	out << a.b << endl;
	out << a.x << endl;
	return out;
}

istream & operator >> (istream& is, parallel& dat)
{
	is >> dat.a;
	is >> dat.b;
	is >> dat.x;
	return is;
}

int main()
{
	setlocale(LC_ALL, "rus");

	parallel obj1;
	parallel c, d(obj1);
	obj1.setParallel();
	obj1.getParallel();
	cout << obj1.perimetr() << endl;
	cout << obj1.area() << endl;
	cin >> obj1;
	cout << obj1;
	cout << "—четчик " <<obj1.getN();
	_getch();
	return 0;
}