#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char b[100];

    char temp = cin.get();
    int len = 1;
    while(temp != '#') {
        len++;
        cout << temp ;
        temp = cin.get();
    }

    cout << "strlen of a: " << len << endl;
}
