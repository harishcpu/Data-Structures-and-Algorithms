#include <iostream>
#include <vector>
using namespace std;

int main() {
    //    vector<int> a;

    //a = {1,2,3,4,5};

    //Fill constructor
    vector<int> a(10, 7);


    a.pop_back();

    // push_back 0(1)
    a.push_back(6);


    cout << a.size() << endl;
    cout << a.capacity() << endl;

    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
