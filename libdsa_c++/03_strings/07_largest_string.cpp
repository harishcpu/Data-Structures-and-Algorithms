#include<iostream>
#include<cstring>
using namespace std;

// Problem: Read N strings and print the largest string. Each string size is 100.
int main() {
    int n;
    int largest_len = 0;
    char sentence[1000];
    char largest[1000];
    cin >> n; //user is pressing new line
    cin.get();
    while(n--) {
        cin.getline(sentence, 1000);
        //cout << sentence << endl;
        int len = strlen(sentence);
        if(len > largest_len) {
            largest_len = len;
            strcpy(largest, sentence);
        }
    }
    
    cout << "Largest sentence is " << largest << endl;
    return 0;
}
