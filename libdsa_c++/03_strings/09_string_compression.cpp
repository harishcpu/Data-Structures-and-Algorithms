#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int compress(vector<char>& chars) {
    // your code goes here
    int i = 0;
    int  j =0;
    int count;
    int len = chars.size();
    int index = -1;
    while(i<len-1) {
        count  = 1;
        while(chars[i] == chars[++j])
            ++count;
        if(count > 1 && count < 10) {
            chars[++index] = chars[i];
            chars[++index] = '0' + count;
        } else if (count >= 10 && count < 100) {
            chars[++index] = chars[i];
            chars[++index] = '0' + (count / 10);
            chars[++index] = '0' + (count % 10);
        } else if(count == 1) {
            chars[++index] = chars[i];
        }
        i = i + count;
    }
    chars[index+1] = '\0';
    for(int i = 0; chars[i] != '\0'; i++)
        cout << chars[i] ;
    cout << endl;
    return index;
}


int main() {
    vector<char> a{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    compress(a);
}
