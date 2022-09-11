#include<iostream>
#include<vector>
using namespace std;

int main() {
    //vector<int> arr = {1,2,3,4,5};
    
    //fill constructor
    vector<int> arr(10, 7);

 //   arr.pop_back();
    arr.push_back(6);

    for(int i=0; i<arr.size();i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << arr.size() << endl;

    cout << arr.capacity() << endl;

    return 0;
}
