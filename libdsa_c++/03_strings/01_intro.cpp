#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char a[] = "abcd"; // {'a', 'b', 'c', 'd', '\0'};
    char b[100];


    cout << a << endl;
    cin >> b;
    cout << b << endl;

    cout << "strlen of a: " << strlen(a) << endl;
    cout << "size of a: " << sizeof(a) << endl;
}
