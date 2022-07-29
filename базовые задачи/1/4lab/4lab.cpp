
#include "stdafx.h" 
#include <iostream> 
#include "C:\Users\user\Documents\Visual Studio 2015\Projects\4lab\4lab\dm2.h"
#include "C:\Users\user\Documents\Visual Studio 2015\Projects\4lab\4lab\heir.h"

int main()
{
	setlocale(LC_ALL, "rus");
	//heir h(5);
	dm d(5, 5);
	d.add(4);
	d.add(1, 2);
	cout << d;
	d.del(2);
	cout << d;
	int q;
	int x[] = { 1,2,3,4 };
	dm m(5, 1), check_summ(5, 2), check_summ1(5, 0), z(0), c(4, x);
	check_summ1 = check_summ + m;
	cout << (check_summ + m);
	cin >> m;
	dm a(m), equ;
	cout << "Z = " << z << "\n |" << a << "\n 4 " << c; // z = NULL, a = copy, c = ? ???????? 
	equ = m;
	cout << "=== " << equ;
	cout << "??????? Q\n";
	cin >> q;
	int s = m.search(q);
	cout << "??????? = " << s << "\n";
	system("pause");
	return 0;


}