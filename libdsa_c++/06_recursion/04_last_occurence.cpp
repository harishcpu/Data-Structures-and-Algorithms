#include <iostream>
using namespace std;

int last_occurence(int a[], int n, int key) {
    if(n<0) return -1;
    int subIdx = last_occurence(a+1, n-1, key);
    if(a[0] == key && subIdx == -1) return 0;
    if(subIdx >= 0) return subIdx+1;
    return -1;
}

int main() {
    int n[] = {1, 0, 7, 4, 5, 6, 7, 8, 9, 0};
    int key;

    cin>>key;    
    cout << last_occurence(n, sizeof(n)/sizeof(n[0]), key);
}
