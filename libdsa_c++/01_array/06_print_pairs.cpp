#include <iostream>
using namespace std;

void printPairs(int a[], int n) {
    for(int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cout << "(" << a[i] << "," << a[j] << ") ";
        }
        cout << endl;
    }
}

int main() {
    //int a[] = {10, 20, 30, 40, 50, 60, 70};
    int a[] = {10, 22, 28, 29, 30, 40};
    int size = sizeof(a)/sizeof(int);

    printPairs(a, size);
    return 0;
}
