#include <iostream>
using namespace std;

int first_occurence(int a[], int n, int key) {
    if(n == -1) return -1;
    if(a[0] == key) return 0;

    int subIdx = first_occurence(a+1, n-1, key);
    if(subIdx == -1)    return -1;
    return 1+subIdx;
}

int main() {
    int n[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int key;

    cin>>key;    
    cout << first_occurence(n, sizeof(n)/sizeof(n[0]), key);
}
