#include <iostream>
using namespace std;

int main() {
    char ch;

    ch = cin.get();

    int alpha = 0, space = 0, digit = 0;
    while(ch!='\n') {
        if(ch >= '0' and ch<='9') {
            digit++;
        }
        else if((ch>='a' and ch <='z') or (ch>='A' and ch<='Z')) {
            alpha++;
        }
        else if (ch==' ' or ch =='\n') {
            space++;
        }
        ch = cin.get();
    }

    cout << "Total Alphabets: " << alpha << endl;
    cout << "Total digits: " << digit << endl;
    cout << "Total spaces: " << space << endl;
}
