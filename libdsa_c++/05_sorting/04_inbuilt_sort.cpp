#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    cout << "Comparing " << a << " and " << b << endl;
    return a<b;
}

int main() {
    int arr[] = {-2, -4, -6, -1, 0, 25, 3, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+n, greater<int>());
    //sort(arr, arr+n, compare);
    //reverse(arr, arr+n);

    for(auto x : arr)
        cout << x << ",";
    cout << endl;
}
