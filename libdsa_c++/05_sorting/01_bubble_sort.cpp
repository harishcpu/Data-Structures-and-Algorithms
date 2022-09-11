#include <iostream>
using namespace std;


void bubble_sort(int arr[], int n) {
    for(int times = 1; times < n; times++) {
        for(int j=0; j<n-1; j++) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

int main() {
    int arr[] = {-2, -4, -6, -1, 0, 25, 3, 9};
    bubble_sort(arr, sizeof(arr)/sizeof(arr[0]));

    for(auto x : arr)
        cout << x << ",";
    cout << endl;
}
