#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int key) {
    // Implement binary search
    
    int s = 0, e = n-1;
    int mid;

    while(s <= e) {
        mid = (s + e)/2;
        if (arr[mid] == key)    return mid;
        else if (arr[mid] < key) s = mid+1;
        else    e = mid-1;
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 10, 11, 19, 29, 30};
    int key;
    cout << "Enter the key to find: ";
    cin >> key;

    int index = binary_search(arr, sizeof(arr)/sizeof(int), key);

    if(index != -1) cout << key << " is present at index " << index << endl;
    else    cout << key << " NOT FOUND" << endl;
}
