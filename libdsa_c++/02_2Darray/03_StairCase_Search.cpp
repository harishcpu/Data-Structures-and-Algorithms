#include<iostream>
#include<vector>
using namespace std;

pair<int, int> staircase_search(vector<vector<int>> a, int row,
                                int column, int key) {
    //if the element is not present
    if(a[0][0] < key and a[row-1][column-1] < key)
        return {-1,-1};

    //staircase search
    int i = 0;
    int j = column-1;
    while(i < row and j >= 0) {
        if(a[i][j] == key)
            return {i,j};
        else if(a[i][j] > key)
            j--;
        else
            i++;
    }
    return {-1,-1};
}

int main() {
    vector<vector<int>> a = { {10,20,30,40},
                              {15,25,35,45},
                              {27,29,37,48},
                              {32,33,39,50},
                            };
    int n = 4, m = 4;
    pair<int, int> coords = staircase_search(a, m, n, 39);
    cout << coords.first << " " << coords.second << endl;
    return 0;
}
