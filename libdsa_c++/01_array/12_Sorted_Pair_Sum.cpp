#include <iostream>
#include <vector>
using namespace std;

pair<int, int> closest_sorted_pair_sum(vector<int> a, int val) {
    int i = 0, j = a.size()-1;
    int closest = 0, current = 0;
    pair<int, int> closest_pair;
    while(i<j) {
        current = a[i]+a[j];

        if(current > closest && current < val) {
            closest = current;
            closest_pair.first = a[i];
            closest_pair.second = a[j];
        }

        cout << i << j << " ";
        if(current == val) {
            closest_pair.first = a[i];
            closest_pair.second = a[j];
            break; 
        }

        if(current > val) j--;
        else i++;
    }
    return closest_pair;
}


int main() {
    //vector<int> a = {-1, -1, 2, 3, 5};
    vector<int> a = {10,22,28,30,40};
    pair<int, int> p = closest_sorted_pair_sum(a, 52); 
    cout << "ans: " << p.first << " " << p.second << endl;
}
