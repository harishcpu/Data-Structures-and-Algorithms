#include <iostream>
using namespace std;

#define FAILURE -1

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 1, 9, 23};

    int key, index;

    cout << "Enter the key: ";
    cin >> key;

    if(FAILURE != (index = linearSearch(arr, sizeof(arr)/sizeof(int), key)))
        cout << "Element " << key << " is found at " << index << endl;
    else
        cout << "Element " << key << " not found" << endl;
        
}
