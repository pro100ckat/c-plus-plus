// ConsoleApplication11.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <istream>
#include <cstdlib>
#include <list>
using namespace std;

template< typename T >
class List {
private:
	// ���������� ��������� ���� ��� ������������� � ������ Iterator
	struct Node;

public:
	// ����� ��������� ������������ ������
	class Iterator {
		public:
			Iterator(Node* node) : m_node(node) { }

			// �������� �� ���������
			bool operator==(const Iterator& other) const {
				if (this == &other) {
					return true;
				}
				return m_node == other.m_node;
			}

			// �������� �� �����������
			bool operator!=(const Iterator& other) const {
				return !operator==(other);
			}

			// ��������� �������� �������� ����
			T operator*() const {
				if (m_node) {
					return m_node->m_t;
				} // ����� ��������� ����� ������. ������� ��������� ����������
				return T();
			}

			// ������� � ���������� ����
			void operator++() {
				if (m_node) {
					m_node = m_node->m_next;
				} // ����� ��������� ����� ������. ������� ��������� ����������
			}

		private:
			Node* m_node;
	
	};

public:
	List();

	~List();

	// ���������� ���� � ������
	void append(const T& t);

	// �������� ���������� ������������ ���� �� ������
	void remove();

	// �������� �������� ������� ������
	T head() const;

	// �������� �������� �� ������ ������
	Iterator begin() const;

	// �������� �������� �� ����� ������
	Iterator end() const;

	// �������� ������ ������
	size_t size() const;

private:
	// ��������� ���� ������������ ������
	struct Node {
		Node() : m_next(NULL) { }

		Node(const T& t) : m_t(t), m_next(NULL) { }

		// �������� ����
		T m_t;

		// ��������� �� ��������� ����
		Node* m_next;
	};

	// ������ ������������ ������
	Node* m_head;
};

template< typename T >
List< T >::List() : m_head(NULL) {}

template< typename T >
void List< T >::append(const T &t) {
	// ������� ����� ���� ��� ��������
	// �� ������� ���������, ��� ������ ������� ��������
	if (Node* node = new Node(t)) 
	{
		// ����� ���� ������������� � ������� ��������� ��������
		node->m_next = m_head;

		// ����� ���� ��� ���������� �������� ���������
		m_head = node;
	}
}



template< typename T >
void List< T >::remove() 
{
	if (m_head) { // ���� ������ �� ����:
				  // ��������� ��������� �� ������ ����, ������� ������ ����� �������� ���������
		Node* newHead = m_head->m_next;

		// ����������� ������, ���������� ��� ���������� ��������� ��������
		delete m_head;

		// ��������� ����� �������� �������
		m_head = newHead;
	} // ����� ����� �� ��������� ����������
}

template<typename T>
T List<T>::head() const
{
	return T();
}


template< typename T >
List< T >::~List() {
	while (m_head) {
		remove();
	}
}


template< typename T >
typename List< T >::Iterator List< T >::begin() const {
	// �������� ������ �� ��������� ��������...
	return Iterator(m_head);
}



template< typename T >
typename List< T >::Iterator List< T >::end() const {
	// ... � �� �����, �.�. NULL
	return Iterator(NULL);
}


template< typename T >
size_t List< T >::size() const {
	size_t s = 0;
	for (Iterator it = begin(); it != end(); ++it) {
		++s;
	}

	/*
	�� ����� � ��� ����������
	for( Node* n = m_head; n != NULL; n = n->m_next ) {
	++s;
	}
	*/

	return s;
}

template <typename T>
void printArray(const T * array, int count)
{
	for (int ix = 0; ix < count; ix++)
		cout << array[ix] << "   ";
	cout << endl;
} // ����� ������� ������� printArray

template <typename T>
void setArray(const T * array, int count)
{
	for (int ix = 0; ix < count; ix++)
		cin >> array[ix];
} // ����� ������� ������� printArray


template <typename T>
T searchMax(const T* array, int size)
{
	T max = array[0]; // ������������ �������� � �������
	for (int ix = 0; ix < size; ix++)
		if (max < array[ix])
			max = array[ix];
	return max;
}



int main()
{
	setlocale(LC_ALL, "rus"); // ������� �����������
	const int iSize = 10,
		dSize = 7,
		fSize = 10,
		cSize = 5;
	// ������� ������ ����� ������
	int    iArray[iSize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 6 };
	double dArray[dSize] = { 1.2345, 2.234, 3.57, 4.67876, 5.346, 6.1545, 7.7682 };
	float  fArray[fSize] = { 1.34, 2.37, 3.23, 4.8, 5.879, 6.345, 73.434, 8.82, 9.33, 10.4 };
	char   cArray[cSize] = { "MARS" };
	cout << "\t\t ������ ������� ������ ������� �� �����\n\n";
	
	
	// ����� ��������� ������ ������� printArray ��� ���� int ����� ������
	cout << "\n������ ���� int:\n"; printArray(iArray, iSize);

	cout << "������������ ������� ������� ���� int: " << searchMax(iArray, 10) << endl;

	
	//// ����� ��������� ������ ������� printArray ��� ���� double ����� ������
	//cout << "\n������ ���� double:\n"; printArray(dArray, dSize);
	//// ����� ��������� ������ ������� printArray ��� ���� float ����� ������
	//cout << "\n������ ���� float:\n"; printArray(fArray, fSize);
	//// ����� ��������� ������ ������� printArray ��� ���� char ����� ������
	//cout << "\n������ ���� char:\n";printArray(cArray, cSize);
	system("pause");
	return 0;
	
}