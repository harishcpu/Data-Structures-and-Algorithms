#include <iostream>
using namespace std;

void printArray(int arr[]) {
    cout << "In function" << sizeof(arr) << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};

    int n = sizeof(arr);

    cout << "In main" << sizeof(arr) << endl;
    printArray(arr);
    return 0;
}
