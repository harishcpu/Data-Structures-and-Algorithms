#include <iostream>
using namespace std;

int fib(int n) {
    if(n ==0 or n==1) {
        return n;
    }

    int ans1 = fib(n-1);
    int ans2 = fib(n-2);
    return ans1+ans2;
}

int main() {
    int n;
    cin>>n;
    cout << fib(n);
}
