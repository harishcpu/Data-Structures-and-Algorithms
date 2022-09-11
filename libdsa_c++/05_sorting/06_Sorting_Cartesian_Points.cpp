#include <iostream>
using namespace std;

vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v) {
    int n = v.size();

    int i = 0;
    while(i<n) {
        int j = 1;
        while(j<n) {
            if(v[j].first < v[i].first) {
                swap(v[i], v[j]);
            } else if(v[j].second < v[i].second) {
                swap(v[i], v[j]);
            }
            j++;
        }
        i++;
    }
    return v;
}

int main() {
    vector<pair<int, int>> v = {(2, 3), (1, 2), (4, 5)};

    vector<pair<int, int>> temp = sortCartesian(v);
    
    for( x : temp ) {
        cout << "(" << x.first << "," << x.second << ") ";
    }
    cout << endl;
}
