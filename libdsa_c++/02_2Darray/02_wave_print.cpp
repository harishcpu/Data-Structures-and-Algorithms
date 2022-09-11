#include<iostream>
using namespace std;

void print(int a[][10], int n, int m) {
    int startRow, startColumn, endRow, endColumn;
    startRow = 0;
    endRow = n-1;
    startColumn = 0;
    endColumn = m-1;

    while(startColumn<=endColumn) {
    //end column
    for(int row = startRow; row<=endRow; row++) {
        cout << a[row][endColumn] << " ";
    }
    endColumn--;
    //start row
    for(int row = endRow; row >= startRow; row--){
        if(endColumn < startColumn)
            break;
       cout << a[row][endColumn] << " ";
    }
    endColumn--;
    }
    cout << endl;
}

int main() {
    //int a[][10] = { {1, 2, 3, 4},
    //                {5, 6, 7, 8},
    //                {9, 10, 11, 12},
    //                {13, 14, 15, 16},
    //              };
    int a[][10] = { {1, 9, 4},
                    {3,6,90},
                    {6, 31, 99},
                  };
    print(a, 3, 3);
}
