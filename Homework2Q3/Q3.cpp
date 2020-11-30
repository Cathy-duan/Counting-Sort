#include<iostream>

using namespace std;

void Countingsort(int A[], int size) {
	
	//find k
	int k=A[0];

	int* B = new int[size];
	for (int a = 1; a < size; a++) {
		if (A[a] > k)
			k = A[a];
	}
	
	int* C = new int[k + 1];
	
	for (int i = 0; i <= k; i++) {
		C[i] = 0;
	}

	for (int j = 0; j <size; j++) {
		C[A[j]] = C[A[j]] + 1;
	}

	//c[i] = |{key = i}|
	for (int i = 1; i <= k; i++) {
		C[i] = C[i] + C[i - 1];
	}
	//c[i] = |{key<=i}|
	for (int j = size-1; j >= 0; j--) {
		B[C[A[j]]-1] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}

	for (int i = 0; i < size; i++) {
		A[i] = B[i];
	}
}
void print(int A[], int n) {
	cout << "{";
	for (int i = 0; i < n; i++) {
		if (i + 1 != n)
			cout << A[i] << ",";
		else
			cout << A[i];
	}
	cout << "}";
}

int main() {
	int A[11]={20,18,5,7,16,10,9,3,12,14,0 };
	cout << "Input array is A = ";
	print(A, 11);
	Countingsort(A, 11);
	cout << "\nOutput array is A = ";
	print(A, 11);
	return 0;
}