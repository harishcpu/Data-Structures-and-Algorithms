/*
Input: 5

Output:
1 2 3 4 5 
-1 -2 -3 -4 -5 
*/

#include <iostream>
using namespace std;

void printArray(int a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

void fillArray(int *a, int i, int n, int val) {
	// base case
	if(i == n) {
		printArray(a, n);
		return;
	}
	
	// recursive case
	a[i] = val;
	fillArray(a, i+1, n, val+1);
	
	// backtracking step
	a[i] = -1 * a[i];
}

int main(void) {
	int a[100];
	int n;
	
	cin >> n;
	fillArray(a, 0, n, 1);
	printArray(a, n);
	
	return 0;
}
