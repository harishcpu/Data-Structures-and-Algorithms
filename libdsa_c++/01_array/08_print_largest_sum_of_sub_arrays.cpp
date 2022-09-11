#include <iostream>
using namespace std;

// Brute Force
int largestSubArraySum1(int a[], int n) {
    int largest_sum = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            // cout << "(" << a[i] << "," << a[j] << ") ";
            sum = 0;
            for(int k = i; k < j; k++) {
                //cout << a[k] << ",";
                sum += a[k];
            }
            //cout << "-> sum = " << sum << endl;
            if(sum > largest_sum)   largest_sum = sum;
        }
    }
    return largest_sum;
}

//Prefix Sums
int largestSubArraySum2(int a[], int n) {
    int largest_sum = 0;
    int sub_array_sum = 0;
    
    int prefix[n] = {0};
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + a[i];

    }

    for(int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
           sub_array_sum = i > 0 ? prefix[j] - prefix[i-1] : prefix[j];
           largest_sum = max(sub_array_sum, largest_sum);
        }
    }
    return largest_sum;
}

// Kadane's algorithm
int largestSubArraySum3(int a[], int n) {
    int largest_sum = 0;
    int current_sum = 0;

    for (int i = 0; i < n; i++) {
        current_sum += a[i];
        if(current_sum < 0) current_sum = 0;
        largest_sum = max(largest_sum, current_sum);
    }

    return largest_sum;
}

int main() {
//    int a[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int a[] = {1, -2, 3, 4, 4, -2};
    int size = sizeof(a)/sizeof(int);
    
    cout << "largest sum of all sub arrays: " << largestSubArraySum1(a, size) << endl;
    cout << "largest sum of all sub arrays: " << largestSubArraySum2(a, size) << endl;
    cout << "largest sum of all sub arrays: " << largestSubArraySum3(a, size) << endl;
    return 0;
}
