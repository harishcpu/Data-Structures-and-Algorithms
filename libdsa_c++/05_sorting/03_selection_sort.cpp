#include <iostream>
using namespace std;


void selection_sort(int arr[], int n) {
    for(int i=0; i<=n-2; i++) {
        int current = arr[i];
        int min_pos = i;
        //find minimum element
        for(int j=i; j<n; j++) {
            if(arr[j] < arr[min_pos])
                min_pos = j;
        }
        swap(arr[min_pos], arr[i]);
    }
}

int main() {
    int arr[] = {-2, -4, -6, -1, 0, 25, 3, 9};
    selection_sort(arr, sizeof(arr)/sizeof(arr[0]));

    for(auto x : arr)
        cout << x << ",";
    cout << endl;
}
