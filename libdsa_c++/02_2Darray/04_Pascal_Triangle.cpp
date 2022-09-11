#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> printPascal(int n)
{
    // your code goes here
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++) {
        if(i < 2) {
            a[i] = vector<int>(i+1);
            for(int j=0; j<i+1; j++) {
                a[i][j] = 1;
            }
        }
        else {
            a[i].push_back(1);
            for(int j=0; (unsigned)j<(unsigned)(i-1); j++) {
                a[i].push_back(a[i-1][j] + a[i-1][j+1]);
            }
            a[i].push_back(1);
        }
    }
    return a;
}

int main() {
    vector<vector<int>> a = printPascal(5);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; (unsigned)j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
