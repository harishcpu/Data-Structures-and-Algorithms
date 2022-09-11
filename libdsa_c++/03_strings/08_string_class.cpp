#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    //string s = "hello world";
    //string s("hello world");
    string s;
    //getline(cin, s, '.');

    //for(char ch:s) {
    //    cout << ch;
    //}
    //cout << endl;

    vector<string> sarr;
    string temp;
    
    int n;
    cin>>  n;
    cin.get();
    while(n--) {
        getline(cin, temp);
        sarr.push_back(temp);
    }

    for(string x : sarr) {
        cout << x << "," << endl;
    }
}
