#include <iostream>
using namespace std;

void printSubArrays(int a[], int n) {
    for(int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // cout << "(" << a[i] << "," << a[j] << ") ";
            for(int k = i; k < j; k++) {
                cout << a[k] << ",";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(a)/sizeof(int);

    printSubArrays(a, size);
    return 0;
}
