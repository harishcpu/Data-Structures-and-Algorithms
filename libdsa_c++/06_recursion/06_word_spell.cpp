#include<iostream>
using namespace std;

string spell[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void print_spell(int num) {
    if(num <= 0)
        return;

    int last_digit = num%10;
    print_spell(num/10);
    cout << spell[last_digit] << " ";
}

int main(void) {
    int num;

    cin >> num;
    print_spell(num);
    cout << "\n";
}
