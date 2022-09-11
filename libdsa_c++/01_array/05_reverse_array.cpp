#include <iostream>
using namespace std;

void reverse_array(int arr[], int n) {
   for(int i = 0, j = n-1; i < j && j > i; i++, j--) {
       swap(arr[i], arr[j]);
   } 
}

int main() {
    int arr[] = {1, 2, 10, 11, 19, 29, 30};

    for(int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    reverse_array(arr, sizeof(arr)/sizeof(int));
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
