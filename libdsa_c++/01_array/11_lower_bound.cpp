#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int lower_bound(vector<int> a, int val) {
    int low, high;
    low = 0, high = a.size()-1;
    int iter = 0;
    int mid;
    while(low < high) {
        mid = low + (high-low)/2;
        cout << "iter: " << iter++ << endl;
        cout << "mid: " << mid << "a[mid]: " << a[mid] << endl;
        if(a[mid] > val)
            high = mid+1;
        else if(a[mid] < val)
            low = mid+1;
        else
            return a[mid];
    }
    return a[mid];
}


int main() {
    //vector<int> a = {-1, -1, 2, 3, 5};
    vector<int> a = {1,2,3,4,6};
    cout << "ans: " << lower_bound(a, 5) << endl;
}
