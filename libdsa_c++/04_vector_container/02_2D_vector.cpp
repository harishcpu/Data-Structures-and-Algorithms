#include<iostream>
#include<vector>
using namespace std;

int main() {
    //2D vector
    vector<vector<int>> arr = {
                                {1,2,3},
                                {5,7,3,9},
                                {3,4},
                                {9,5,7,4,3}
                              };
    for(int i=0; i<arr.size(); i++) {
        for(int x : arr[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
