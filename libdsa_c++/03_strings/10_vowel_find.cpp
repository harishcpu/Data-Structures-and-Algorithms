#include<bits/stdc++.h>
using namespace std;

string vowel(string S){
    // your code goes here
    int len = S.length();
    int i = 0, index = 0;
    while(i < len) {
        switch(S[i++]) {
            case 'a':
                S[index++] = 'a';
                break;
            case 'e':
                S[index++] = 'e';
                break;
            case 'i':
                S[index++] = 'i';
                break;
            case 'o':
                S[index++] = 'o';
                break;
            case 'u':
                S[index++] = 'u';
                break;
        }
    }
    S.resize(index);
    return S;
} 

int main() {
    string s = "aeoibsddaeioudb";
    cout << vowel(s) << endl;
}
