#include<bits/stdc++.h>
using namespace std;
 
 vector<int> print(int m, int n, vector<vector<int>> a)
{
    // your code goes here
    int startRow, startColumn, endRow, endColumn;
    startRow = 0;
    endRow = m-1;
    startColumn = 0;
    endColumn = n-1;
    vector<int> b(m*n);
    int index = 0;
    while(startColumn<=endColumn) {
        //end column
        for(int row = startRow; row<=endRow; row++) {
            cout << a[row][endColumn] << " ";
            b[index++] =  a[row][endColumn];
        }
        endColumn--;
        //start row
        for(int row = endRow; row >= startRow && endColumn >= startColumn; row--){
            cout << a[row][endColumn] << " ";
            b[index++] =  a[row][endColumn];
        }
        endColumn--;
    }
    cout << endl;
    return b;
}

// Driver code
int main() {
    vector<vector<int>> a= { {1, 9, 4},
                    {3,6,90},
                    {6, 31, 99},
                  };
    vector<int> b = print(3, 3, a);
    for (int x : b) {
        cout << x << " ";
    }
    cout << endl;
}
