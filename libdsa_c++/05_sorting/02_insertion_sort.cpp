#include <iostream>
using namespace std;


void insertion_sort(int arr[], int n) {
    for(int i = 1; i<=n-1; i++) {
        int j = i-1;
        int temp = arr[i];
        for(;j>=0 and arr[j] > temp; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}

int main() {
    int arr[] = {-2, -4, -6, -1, 0, 25, 3, 9};
    insertion_sort(arr, sizeof(arr)/sizeof(arr[0]));

    for(auto x : arr)
        cout << x << ",";
    cout << endl;
}
