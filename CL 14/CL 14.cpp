#include "myarray.h"

int main() {
	int size = fillArray();
	int n;
	int* ar = new int[size];
	userFillArray(size, ar);
	printArray(size, ar);
	//randArray(size, ar);
	// ==============================================
	addArrayStart(size, ar);
	//addArrayEnd(size, ar);
	//addArrayMid(size, ar);
	printArray(size, ar);
	// ==================================================
	cout << "choose what to delete\n";
	cin >> n;
	delArrayStart(size, ar);
	//delArrayEnd(size, ar);
	//delArrayMid(size, ar, n);
	printArray(size, ar);
	// ==================================================
	delete[] ar;
}