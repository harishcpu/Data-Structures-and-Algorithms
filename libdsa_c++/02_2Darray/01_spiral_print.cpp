#include<iostream>
using namespace std;

void print(int a[][10], int n, int m) {
    int startRow, startColumn, endRow, endColumn;
    startRow = 0;
    endRow = n-1;
    startColumn = 0;
    endColumn = m-1;

    while(startColumn<=endColumn and startRow<=endRow) {
    //start row
    for(int column = startColumn; column <= endColumn; column++){
       cout << a[startRow][column] << " ";
    }
    //end column
    for(int row = startRow+1; row<=endRow; row++) {
        cout << a[row][endColumn] << " ";
    }
    //end row
    for(int column = endColumn-1; column >= startColumn; column--) {
        if(startRow==endRow)
            break;
        cout << a[endRow][column] << " ";
    }
    //start column
    for(int row = endRow-1; row>startRow; row--) {
        if(startColumn==endColumn)
            break;
        cout << a[row][startColumn] << " ";
    }

    startRow++;
    endColumn--;
    endRow--;
    startColumn++;
    }
    cout << endl;
}

int main() {
    int a[][10] = { {1, 2, 3, 4},
                    {12, 13, 14, 5},
        //            {11, 16, 15, 6},
                    {10, 9, 8, 7}
                  };
    print(a, 3, 4);
}
