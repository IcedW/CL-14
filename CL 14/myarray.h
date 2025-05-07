#include <iostream>
#include <windows.h>
using namespace std;

int fillArray() {
	int a;
	cout << "Please, enter size of array (5-100000): ";
	cin >> a;
	// ����������� ������� ��������
	if (a <= 0) a = 5;
	if (a > 100000) a = 100000;
	return a;
}

void randArray(int a, int* b) {
	srand(time(0));
	for (int i = 0; i < a; i++)
	{
		b[i] = rand() % 100; // 0-99
		cout << b[i] << ", ";
	}
	cout << "\n";
}

void printArray(int a, int* b) {
	for (int i = 0; i < a; i++)
	{
		cout << b[i] << ", ";
	}
	cout << "\n";
}

void addArrayStart(int& a, int*& b) {
	int value;
	cout << "Please, input number to add into array: ";
	cin >> value;
	int* temp = new int[a + 1];
	temp[0] = value;
	for (int i = 0; i < a; i++) {
		temp[i + 1] = b[i];
	}
	temp[a] = value;
	delete[] b;
	b = temp;
	a++;
}

void addArrayEnd(int& a, int*& b) {
	int value;
	cout << "Please, input number to add into array: ";
	cin >> value;

	// �������� ��������� �������� � ����� ������
	// 1) �������� �� ���� �����, ������� �������� ����� �� 1 ����� �� � ������������ (�������) ������
	// 2) �������� ������ ������ ������ ������ � ������� ���������� ��������
	int* temp = new int[a + 1];
	// 3) ��������� ����, ���� �������� �� �������� � ������� ������ � ����� (������ �������� �� �������� 0-0 1-1 2-2 3-3 4-4
	for (int i = 0; i < a; i++)
	{
		temp[i] = b[i];
	}
	// 4) � ����� ������ ������ ����� ������ ������� ��������
	temp[a] = value;
	// 5) ��������� ���'��� �� ������� ������ (������)
	delete[] b;
	// 6) ����������� �������� �� ����� �����
	b = temp;
	// 7) �������� ������� �������� �� 1 � ����� ����
	a++;
}

void addArrayMid(int& a, int*& b) {
	int value;
	int position;
	cout << "num: ";
	cin >> value;
	cout << "position: ";
	cin >> position;
	if (position < 0) position = 0;
	if (position > a) position = a;
	int* n = new int[a + 1];
	for (int i = 0; i < position; i++) {
		n[i] = b[i];
	}
	n[position] = value;
	for (int i = position; i < a; i++) {
		n[i + 1] = b[i];
	}

	delete[] b;
	b = n;
	a++;
}

void delArrayStart(int& a, int*& b) {
	if (a <= 0) return;

	int* temp = new int[a - 1];
	for (int i = 1; i < a; i++) {
		temp[i - 1] = b[i];
	}

	delete[] b;
	b = temp;
	a--;
}

void delArrayEnd(int& a, int*& b) {
	if (a <= 0) return;

	int* temp = new int[a - 1];
	for (int i = 0; i < a - 1; i++) {
		temp[i] = b[i];
	}

	delete[] b;
	b = temp;
	a--;
}

void delArrayMid(int& a, int*& b, int c) {
	int* temp = new int[a - 1];
	for (int i = 0, j = 0; i < a; i++) {
		if (i == c) continue;
		temp[j++] = b[i];
	}
	delete[] b;
	b = temp;
	a--;
}

void userFillArray(int a, int* b) {
	cout << "insert " << a << " values\n";
	for (int i = 0; i < a; i++) {
		cout << "[" << i << "]: ";
		cin >> b[i];
	}
}