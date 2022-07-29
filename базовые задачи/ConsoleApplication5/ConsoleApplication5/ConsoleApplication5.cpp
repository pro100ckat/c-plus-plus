// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
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
	friend istream &operator>> (istream &, dm &); // перегруженный оператор ввода
	friend ostream &operator<< (ostream &, const dm &); // перегруженный оператор вывода
private:
	int *a;
	int n;
public:
		//dm(); //конструктор по умолчанию
		dm ( const dm& x); //конструктор копирования
		~dm(); //деструктор
		dm(int k = 0, int y = 0); // длина и элемент массива
		dm(int k, int *x); // передается по ссылке
		dm & operator = (const dm&x);
		void getarray();
		void setarray();
		int getSize() const; // возвратить количество элементов массива
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
	cout << "конструктор\n ";
	//if (n == 0) a = nullptr;
	if (n == 0) {
		n = 10; // по умолчанию размер массива = 10 элементов
		a = new int[n]; // выделить место в памяти для массива
		for (int i = 0; i < n; i++) // обнуляем массив
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





int dm::getSize() const // возвратить количество элементов массива
{
	return n;
}





dm::dm(int k, int *x)
{
	int i;
	cout << "конструктор\n ";
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




dm::~dm() // десструктор класса Array
{
	delete[] a; // освободить память, удалив массив
}




void dm::getarray() // вывод массива
{
	for (int i = 0; i < n; i++)
		cout << " " << a[i]; // вывод элементов массива на экран

	cout << std::endl; // новая строка
}



void dm::setarray() // заполнение массива
{
	for (int i = 0; i < n; i++)
		cin >> a[i]; // ввод элемента массива с клавиатуры
}





//dm::dm() // конструктор по умолчанию, без параметров
//{
//	n = 10; // по умолчанию размер массива = 10 элементов
//	a = new int[n]; // выделить место в памяти для массива
//	for (int i = 0; i < n; i++) // обнуляем массив
//		a[i] = 5;
//}

// перегруженный оператор ввода, для ввода значений массива с клавиатуры
istream &operator>> (istream & input, dm &obj)
{
	for (int i = 0; i < obj.n; i++)
		input >> obj.a[i]; // заполняем массив объекта obj
	return input; // позволяет множественный ввод, типа cin >> x >> y >> z >> ...
}

// перегруженный оператор вывода для класса Array (вывод элементов массива на экран)
ostream &operator<< (ostream &output, const dm &obj)
{
	for (int i = 0; i < obj.n; i++)
	{
		output << "  " // под каждое число выделяется 5 позиций
			<< obj.a[i];
	}

	output << std::endl; // перенос маркера на новую строку

	return output; // позволяет множественный вывод, типа cout << x << y << z << ...
}


int main()
{
	setlocale(LC_ALL, "rus");
	dm myArray1;     // 10-ти элементный объект класса Array, по умолчанию
	dm myArray2(15,5); // 15-ти элементный объект класса Array

	cout << "Размер массива myArray1: " << myArray1.getSize() << endl;
	cout << "Элементы массива myArray1, после его создания:\n";
	myArray1.getarray(); // вывод элементов массива с помощью метода класса Array

	cout << "Размер массива myArray2: " << myArray2.getSize() << endl;
	cout << "Элементы массива myArray2, после его создания:\n";
	cout << myArray2; // вывод элементов массива с помощью перегруженного оператора вывода

	cout << "Введите 10 чисел: ";
	myArray1.setarray(); // заполнение массива с помощью метода класса Array

						 // введенный массив
	cout << "Введенный массив: " << myArray1;

	cout << "Введите 15 чисел: ";
	cin >> myArray2; // заполнение массива с помощью перегруженного оператора ввода

					 // введенный массив
	cout << "Введенный массив: " << myArray2;

	system("pause");
    return 0;
}

