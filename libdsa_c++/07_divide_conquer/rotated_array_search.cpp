/* Rotated Array Search */

#include <iostream>
#include <vector>
using namespace std;

int rotated_array_search(vector<int> a, int key, int s, int e)
{
    int mid;
    
    while(s<=e) {
        mid = (s+e)/2;
        if(a[mid] == key)
            return mid;
        
        //left
        if(a[s] <= a[mid]) {
            if(key >= a[s] and key <= a[mid])
                e = mid-1;
            else
                s = mid+1;
        }
        //right
        else {
            if(key >= a[mid] and key <= a[e])
                s = mid+1;
            else
                e = mid-1;
        }
    }
    
    return -1;
}

int main() {
    vector<int> a{4, 5, 6, 7, 0, 1, 2, 3};
    int key;
    
    cin >> key;
    cout << rotated_array_search(a, key, 0, a.size()-1);
    return 0;
}
