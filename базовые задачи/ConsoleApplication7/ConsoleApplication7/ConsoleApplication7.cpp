// ConsoleApplication7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "ostream"
#include "iostream"
#include <iomanip> // для манипулятора setw
#include <cstdlib>
using namespace std;


class arr_d // имя класса

{

	friend istream& operator>>(istream &input, const arr_d &x)    // перегруженный оператор ввода, для ввода значений массива с клавиатуры
	{
					for (int i = 0; i < x.size; i++)
				input >> x.array[i]; // заполняем массив объекта obj
			return input; // озволяет множественный ввод, типа cin >> x >> y >> z >> ...
	}
	friend ostream & operator<<(ostream &output, const arr_d & x) {// перегруженный оператор вывода для класса Array (вывод элементов массива на экран)

		
			for (int i = 0; i < x.size; i++)
			{
				output << setw(5) // под каждое число выделяется 5 позиций
					<< x.array[i];
			}

			output << endl; // перенос маркера на новую строку

			return output; // позволяет множественный вывод, типа cout << x << y << z << ...
		
	}


public: // спецификатор доступа
	
	arr_d operator+ (const arr_d &right) 
	{
		if (size != right.size)
		{
			cout << "Массивы разного размера!\n";
			exit(1); // завершить работу программы
		}

		arr_d result(size);
		for (int i = 0; i < size; i++)
			result.array[i] = array[i] + right.array[i];

		return result; // вернуть сумму
	}
	friend int operator* (const arr_d &left, const arr_d &right)
	{
		if (left.size != right.size)
		{
			cout << "Массивы разного размера!\n";
			exit(1); // завершить работу программы
		}
		int result = 0;
		for (int i = 0; i < left.size; i++)
		{
			result += left.array[i] * right.array[i];
		}
		return result;
	}
	arr_d() // конструктор по умолчанию, без параметров
	{

		size = 3; // по умолчанию размер массива = 5 элементов
		array = new int[size]; // выделить место в памяти для массива
		for (int i = 0; i < size; i++) // обнуляем массив
			array[i] = 0;

	}
	arr_d(int arraysize) // конструктор с параметрами
	{
		// если значение параметра больше 0, присвоить size значение arraySize, иначе - 10
		size = (arraysize > 0 ? arraysize : 10);
		array = new int[size]; // выделить место в памяти для массива

		for (int i = 0; i < size; i++) // обнуляем массив
			array[i] = 0;
	}
	~arr_d()
	{
		cout << "destr\n";
		if (!array) delete[] array;
	}
	void setArray() // заполнение массива
	{
		for (int i = 0; i < size; i++)
			cin >> array[i]; // ввод элемента массива с клавиатуры
	}
	void getArray() // вывод массива
	{
		for (int i = 0; i < size; i++)
			cout << setw(5) << array[i]; // вывод элементов массива на экран

		cout << std::endl; // новая строка
	}

	
protected:
	int *array;
	int size;
}; 

// конец объявления класса arr_d

// Начало объявления класса Многочлен наследника 
class mnogochlen : public arr_d
{
public:

	mnogochlen() : arr_d() 
	{}
	mnogochlen(int arraysize) : arr_d(arraysize)
	{}
	~mnogochlen() 
	{
		cout << "destr\n";
	}
};
// Конец обЪявления класса многочлен наследник
	


int main()
{	
	
setlocale(LC_ALL, "rus"); // русская локализация
arr_d dm1(3);   // 5-ти элементный объект класса Array
arr_d dm2(3); // 7-ти элементный объект класса Array
cout << "Элементы массива myArray1, после его создания:\n";
dm1.getArray(); // вывод элементов массива с помощью метода класса Array
cout << "Элементы массива myArray2, после его создания:\n";
cout << dm2; // вывод элементов массива с помощью перегруженного оператора вывода
cout << "Введите 3 чисел ";				
cin >> dm2;
cout << "Введенный массив: " << dm2; // введенный массив

mnogochlen s1;
mnogochlen s2(3);
cout << "Коэффицианты многочлена s1, после его создания:\n";
s1.getArray();
cout << "Коэффицианты многочлена s2, после его создания:\n";
cout << s2; // вывод элементов массива с помощью перегруженного оператора вывода
cout << "Введите 3 коэффициентов ";
cin >> s1;
cout << "Коэффициенты многочлена s1: " << s1; // введенный массив
cout << "Введите 3 коэффициентов s2";
cin >> s2;
cout << "Коэффициенты многочлена s2: " << s2; // введенный массив
mnogochlen s3(3);
cout << "Сумма многочленов: " << s3 + s1 + s2;
cout << "Ghjbpdtl многочленов: " << s3 * s1 * s2;
system("pause");
return 0;

}

