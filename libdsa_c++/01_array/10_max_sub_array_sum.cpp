#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumSubarray(vector<int> a, int n) {
    int lsum, csum;
    lsum = INT_MIN;
    csum = 0;

    for(int i = 0; i < n; i++) {
        csum += a[i];
        if(csum > lsum)
            lsum = csum;
        if(csum < 0)
            csum = 0;
    }
    return lsum;
}


int main() {
    vector<int> a = {1, -2, 3, 4, 4, -2};
    cout << "ans: " << maxSumSubarray(a, a.size()) << endl;
}
