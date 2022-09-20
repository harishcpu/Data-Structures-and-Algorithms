
#include <bits/stdc++.h>
using namespace std;
  
int binSearch(vector<int> v, int x, int s, int e) {
    if(v[s] == x)
        return s;
    if(s>=e)
        return -1;
    if(v[(s+e)/2] == x)
        return (s+e)/2;
    
    int mid = (s+e)/2;
    if(v[mid] < x)
        return binSearch(v, x, mid+1, e);
    else if (v[mid] > x)
        return binSearch(v, x, s, mid-1);
    else
        return mid;
}

int binarySearch(vector<int> v, int x)
{
    // your code goes here
    return binSearch(v, x, 0, v.size()-1);
}

int main() {
    vector<int> a{0, 3, 5, 7, 9, 15};
    int x = 7;
    cout << x << " is present at index " << binarySearch(a, x);
}
