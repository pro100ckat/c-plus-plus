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
			output << setw(5) << x.array[i] << "x^" << x.size - i - 1;
		}

		output << endl; // перенос маркера на новую строку

		return output; // позволяет множественный вывод, типа cout << x << y << z << ...

	}
	friend const arr_d& operator++(arr_d& arr) 
	{
		for (int i = 0; i < arr.size; i++)
		{
			arr.array[i]++;
		}
		return arr;
	}	//префиксный инкремент
	friend const arr_d operator++(arr_d& arr, int) 
	{
		arr_d oldValue(arr);
		for (int i = 0; i < arr.size; i++)
		{
			arr.array[i]++;
		}
		return oldValue;
	} //постфиксный инкремент
	 



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
	arr_d operator- (const arr_d &right)
	{
		if (size != right.size)
		{
			cout << "Массивы разного размера!\n";
			exit(1); // завершить работу программы
		}

		arr_d result(size);
		for (int i = 0; i < size; i++)
			result.array[i] = array[i] - right.array[i];

		return result; // вернуть сумму
	}
	arr_d operator* (const arr_d &right)
	{
		if (size != right.size)
		{
			cout << "Массивы разного размера!\n";
			exit(1); // завершить работу программы
		}

		arr_d result(size);
		for (int i = 0; i < size; i++)
			result.array[i] = array[i] * right.array[i];

		return result; // вернуть сумму
	}
	arr_d operator/ (const arr_d &rigth)
	{
		arr_d temp;
		arr_d ob_1;
		arr_d ob_2;
		arr_d ob_4;

		temp.size = size - rigth.size;
		temp.array = new int[temp.size + 1];
		memset(temp.array, 0, (temp.size + 1)*sizeof(double));

		ob_1.size = size;
		ob_1.array = new int[size + 1];
		for (int i = size;i >= 0;i--)
			ob_1.array[i] = array[i];


		ob_2.size = rigth.size;
		ob_2.array = new int[rigth.size + 1];
		for (int i = rigth.size;i >= 0;i--)
			ob_2.array[i] = rigth.array[i];

		ob_4.size = rigth.size;
		ob_4.array = new int[ob_1.size + 1];

		int u = 0;
		int j = 0;
		int k = ob_1.size;
		while (u == 0)
		{
			if (ob_1.size >= ob_2.size)
			{
				j = ob_2.size;
				for (int i = ob_1.size; i >= 0; i--)
				{
					if (j >= 0)
					{
						ob_4.array[i] = ob_2.array[j];
						j--;
					}
					else ob_4.array[i] = 0;
				}


				for (int i = 0; i <= ob_1.size; i++)
					ob_4.array[i] *= ob_1.array[k];

				temp.array[ob_1.size - 1] = ob_1.array[k];

				for (int i = 0; i <= ob_1.size; i++)
					ob_1.array[i] -= ob_4.array[i];

			}
			else u = 1;
			k--;
			ob_1.size--;
		}
		return temp;
	}


	arr_d &operator+= (const int &number)
	{

		arr_d result(size);
		result = *this; // временно сохраним текущий массив

		delete[] array; // освобождаем память

		size = size + 1; // увеличиваем размер массива на 1
		array = new int[size]; // выделяем память

		for (int i = 0; i < (size - 1); i++)
			array[i] = result.array[i]; // скопировать массив

		array[size - 1] = number; // добавляем число в конец массива

		return *this; // каскадный вызов перегруженного оператора
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
	void add(int key, int k = -1) {
		if (k == -1)
		{
			int *result = new int[size + 1];
			for (int i = 0; i < size; i++)
			{
				result[i] = array[i];
			}
			if (array != NULL)
			{
				delete[] array;
			}
			size =size + 1;
			array = result;
			array[size - 1] = key;
		}
		else
		{
			if (k > 0)
			{
				int * result = new int[size + 1];
				for (int i = 0; i < k - 1; i++)
				{
					result[i] = array[i];
				}
				result[k - 1] = key;
				size = size + 1;
				for (int i = k - 1; i < size; i++)
				{
					result[i + 1] = array[i];
				}
				if (array != NULL)
				{
					delete[] array;
				}
				array = result;
			}
		}
	}
	void del(int index) {
		if ((index > 0) & (index < size))
		{
			int * result = new int[size - 1];
			for (int i = 0; i < index - 1; i++)
			{
				result[i] = array[i];
			}
			size	= size - 1;
			for (int i = index - 1; i < size; i++)
			{
				result[i] = array[i + 1];
			}
			if (array != NULL)
			{
				delete[] array;
			}
			array = result;
		}
	}
	void umn(int k)
	{
		for (int i = 0; i < size; i++)
		{
			array[i] = array[i]*k;
		}

	}

	//private:

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
	void addm(int key, int k)
	{
		
			array[size - k-1] = array[size - k-1] + key;
	}
};
// Конец обЪявления класса многочлен наследник



int main()
{

	setlocale(LC_ALL, "rus"); // русская локализация
	//arr_d dm1;   // 5-ти элементный объект класса Array
	//arr_d dm2(7); // 7-ти элементный объект класса Array
	//cout << "Элементы массива myArray1, после его создания:\n";
	//dm1.getArray(); // вывод элементов массива с помощью метода класса Array
	//cout << "Элементы массива myArray2, после его создания:\n";
	//dm2.getArray(); // вывод элементов массива с помощью метода класса Array
	//cout << "Введите 7 чисел ";
	//cin >> dm2;
	//cout << "Введенный массив: "; // введенный массив
	//dm2.getArray(); // вывод элементов массива с помощью метода класса Arra
	//dm2++; 
	//cout << "Введенный массив: " << dm2; // введенный массив
	//++dm2;
	//cout << "Введенный массив: " << dm2; // введенный массив
	//dm2.add(5,2);
	//cout << "Введенный массив: " << dm2; // введенный массив


	mnogochlen s1;
	mnogochlen s2(5);
	cout << "Коэффицианты многочлена s1, после его создания:\n";
	cout << s1;
	cout << "Коэффицианты многочлена s2, после его создания:\n";
	cout << s2; // вывод элементов массива с помощью перегруженного оператора вывода
	cout << "Введите 3 коэффициента ";
	cin >> s1;
	cout << "Коэффициенты многочлена s1: " << s1; // введенный массив
	cout << "Введите 3 коэффициента s2";
	cin >> s2;
	cout << "Коэффициенты многочлена s2: " << s2; // введенный массив
	cout << "Сумма многочленов: " << s1 + s2;
	cout << "Разность многочленов" << s1 - s2;
	cout << "Деления многочленов" << s1/s2;
	cout << "Постфиксный s1: " << s1++;
	cout << "Префиксный s2: " << ++s2;
	s1.addm(5, 2);
	cout << "Addm: Добавить 5x^2 к s1" << s1;
	int n;
	cout << "Введи коэф умножения";
	cin >> n;
	s1.umn(n);
	cout << "Умножить: " << s1;
	
	system("pause");
	return 0;

}

