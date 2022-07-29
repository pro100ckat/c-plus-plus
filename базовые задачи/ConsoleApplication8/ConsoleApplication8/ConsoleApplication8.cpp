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
			output << setw(5) << x.array[i] << "x^" << x.size - i - 1;
		}

		output << endl; // ������� ������� �� ����� ������

		return output; // ��������� ������������� �����, ���� cout << x << y << z << ...

	}
	friend const arr_d& operator++(arr_d& arr) 
	{
		for (int i = 0; i < arr.size; i++)
		{
			arr.array[i]++;
		}
		return arr;
	}	//���������� ���������
	friend const arr_d operator++(arr_d& arr, int) 
	{
		arr_d oldValue(arr);
		for (int i = 0; i < arr.size; i++)
		{
			arr.array[i]++;
		}
		return oldValue;
	} //����������� ���������
	 



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
	arr_d operator- (const arr_d &right)
	{
		if (size != right.size)
		{
			cout << "������� ������� �������!\n";
			exit(1); // ��������� ������ ���������
		}

		arr_d result(size);
		for (int i = 0; i < size; i++)
			result.array[i] = array[i] - right.array[i];

		return result; // ������� �����
	}
	arr_d operator* (const arr_d &right)
	{
		if (size != right.size)
		{
			cout << "������� ������� �������!\n";
			exit(1); // ��������� ������ ���������
		}

		arr_d result(size);
		for (int i = 0; i < size; i++)
			result.array[i] = array[i] * right.array[i];

		return result; // ������� �����
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
		result = *this; // �������� �������� ������� ������

		delete[] array; // ����������� ������

		size = size + 1; // ����������� ������ ������� �� 1
		array = new int[size]; // �������� ������

		for (int i = 0; i < (size - 1); i++)
			array[i] = result.array[i]; // ����������� ������

		array[size - 1] = number; // ��������� ����� � ����� �������

		return *this; // ��������� ����� �������������� ���������
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
	void addm(int key, int k)
	{
		
			array[size - k-1] = array[size - k-1] + key;
	}
};
// ����� ���������� ������ ��������� ���������



int main()
{

	setlocale(LC_ALL, "rus"); // ������� �����������
	//arr_d dm1;   // 5-�� ���������� ������ ������ Array
	//arr_d dm2(7); // 7-�� ���������� ������ ������ Array
	//cout << "�������� ������� myArray1, ����� ��� ��������:\n";
	//dm1.getArray(); // ����� ��������� ������� � ������� ������ ������ Array
	//cout << "�������� ������� myArray2, ����� ��� ��������:\n";
	//dm2.getArray(); // ����� ��������� ������� � ������� ������ ������ Array
	//cout << "������� 7 ����� ";
	//cin >> dm2;
	//cout << "��������� ������: "; // ��������� ������
	//dm2.getArray(); // ����� ��������� ������� � ������� ������ ������ Arra
	//dm2++; 
	//cout << "��������� ������: " << dm2; // ��������� ������
	//++dm2;
	//cout << "��������� ������: " << dm2; // ��������� ������
	//dm2.add(5,2);
	//cout << "��������� ������: " << dm2; // ��������� ������


	mnogochlen s1;
	mnogochlen s2(5);
	cout << "������������ ���������� s1, ����� ��� ��������:\n";
	cout << s1;
	cout << "������������ ���������� s2, ����� ��� ��������:\n";
	cout << s2; // ����� ��������� ������� � ������� �������������� ��������� ������
	cout << "������� 3 ������������ ";
	cin >> s1;
	cout << "������������ ���������� s1: " << s1; // ��������� ������
	cout << "������� 3 ������������ s2";
	cin >> s2;
	cout << "������������ ���������� s2: " << s2; // ��������� ������
	cout << "����� �����������: " << s1 + s2;
	cout << "�������� �����������" << s1 - s2;
	cout << "������� �����������" << s1/s2;
	cout << "����������� s1: " << s1++;
	cout << "���������� s2: " << ++s2;
	s1.addm(5, 2);
	cout << "Addm: �������� 5x^2 � s1" << s1;
	int n;
	cout << "����� ���� ���������";
	cin >> n;
	s1.umn(n);
	cout << "��������: " << s1;
	
	system("pause");
	return 0;

}

