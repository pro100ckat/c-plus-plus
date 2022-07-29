// ConsoleApplication7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "ostream"
#include "iostream"
#include <iomanip> // ��� ������������ setw
#include <cstdlib>
using namespace std;


class arr_d // ��� ������

{

	friend istream& operator>>(istream &input, const arr_d &x)    // ������������� �������� �����, ��� ����� �������� ������� � ����������
	{
					for (int i = 0; i < x.size; i++)
				input >> x.array[i]; // ��������� ������ ������� obj
			return input; // �������� ������������� ����, ���� cin >> x >> y >> z >> ...
	}
	friend ostream & operator<<(ostream &output, const arr_d & x) {// ������������� �������� ������ ��� ������ Array (����� ��������� ������� �� �����)

		
			for (int i = 0; i < x.size; i++)
			{
				output << setw(5) // ��� ������ ����� ���������� 5 �������
					<< x.array[i];
			}

			output << endl; // ������� ������� �� ����� ������

			return output; // ��������� ������������� �����, ���� cout << x << y << z << ...
		
	}


public: // ������������ �������
	
	arr_d operator+ (const arr_d &right) 
	{
		if (size != right.size)
		{
			cout << "������� ������� �������!\n";
			exit(1); // ��������� ������ ���������
		}

		arr_d result(size);
		for (int i = 0; i < size; i++)
			result.array[i] = array[i] + right.array[i];

		return result; // ������� �����
	}
	friend int operator* (const arr_d &left, const arr_d &right)
	{
		if (left.size != right.size)
		{
			cout << "������� ������� �������!\n";
			exit(1); // ��������� ������ ���������
		}
		int result = 0;
		for (int i = 0; i < left.size; i++)
		{
			result += left.array[i] * right.array[i];
		}
		return result;
	}
	arr_d() // ����������� �� ���������, ��� ����������
	{

		size = 3; // �� ��������� ������ ������� = 5 ���������
		array = new int[size]; // �������� ����� � ������ ��� �������
		for (int i = 0; i < size; i++) // �������� ������
			array[i] = 0;

	}
	arr_d(int arraysize) // ����������� � �����������
	{
		// ���� �������� ��������� ������ 0, ��������� size �������� arraySize, ����� - 10
		size = (arraysize > 0 ? arraysize : 10);
		array = new int[size]; // �������� ����� � ������ ��� �������

		for (int i = 0; i < size; i++) // �������� ������
			array[i] = 0;
	}
	~arr_d()
	{
		cout << "destr\n";
		if (!array) delete[] array;
	}
	void setArray() // ���������� �������
	{
		for (int i = 0; i < size; i++)
			cin >> array[i]; // ���� �������� ������� � ����������
	}
	void getArray() // ����� �������
	{
		for (int i = 0; i < size; i++)
			cout << setw(5) << array[i]; // ����� ��������� ������� �� �����

		cout << std::endl; // ����� ������
	}

	
protected:
	int *array;
	int size;
}; 

// ����� ���������� ������ arr_d

// ������ ���������� ������ ��������� ���������� 
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
// ����� ���������� ������ ��������� ���������
	


int main()
{	
	
setlocale(LC_ALL, "rus"); // ������� �����������
arr_d dm1(3);   // 5-�� ���������� ������ ������ Array
arr_d dm2(3); // 7-�� ���������� ������ ������ Array
cout << "�������� ������� myArray1, ����� ��� ��������:\n";
dm1.getArray(); // ����� ��������� ������� � ������� ������ ������ Array
cout << "�������� ������� myArray2, ����� ��� ��������:\n";
cout << dm2; // ����� ��������� ������� � ������� �������������� ��������� ������
cout << "������� 3 ����� ";				
cin >> dm2;
cout << "��������� ������: " << dm2; // ��������� ������

mnogochlen s1;
mnogochlen s2(3);
cout << "������������ ���������� s1, ����� ��� ��������:\n";
s1.getArray();
cout << "������������ ���������� s2, ����� ��� ��������:\n";
cout << s2; // ����� ��������� ������� � ������� �������������� ��������� ������
cout << "������� 3 ������������� ";
cin >> s1;
cout << "������������ ���������� s1: " << s1; // ��������� ������
cout << "������� 3 ������������� s2";
cin >> s2;
cout << "������������ ���������� s2: " << s2; // ��������� ������
mnogochlen s3(3);
cout << "����� �����������: " << s3 + s1 + s2;
cout << "Ghjbpdtl �����������: " << s3 * s1 * s2;
system("pause");
return 0;

}

