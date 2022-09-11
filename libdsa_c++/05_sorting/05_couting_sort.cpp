#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void counting_sort(int arr[], int n) {
    //find the largest
    int largest = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > largest)    largest = arr[i];
    }

    //int *a = new int[largest];
    vector<int> a(largest+1, 0);

    for(int i = 0; i < n; i++) {
        ++a[arr[i]];
    }

    for(int i=0, j=0; i <= largest; i++) {
        while(a[i]-- > 0)
            arr[j++] = i;
    }
}

int main() {
    int arr[] = {88, 12, 54, 67, 23, 23, 45, 13, 9, 0, 3, 37};
    int n = sizeof(arr)/sizeof(arr[0]);
    counting_sort(arr, n);

    for(auto x : arr)
        cout << x << ",";
    cout << endl;
}
