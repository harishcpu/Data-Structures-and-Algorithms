#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int calcTotalMarks(vector<int> a) {
    return a[0]+a[1]+a[2];
}

bool compare(pair<string, vector<int>> s1, pair<string, vector<int>> s2)  {
    return calcTotalMarks(s1.second) > calcTotalMarks(s2.second);
}

int main() {
    vector<pair<string, vector<int>>> student_marks = {
        {"Harish", {10,20,11}},
        {"Rahul", {10,21,3}},
        {"Rohan", {5,5,6}},
        {"Rijul", {10,13,20}},
    };

    sort(student_marks.begin(), student_marks.end(), compare);
    for(auto s : student_marks) {
        cout << s.first << " " << calcTotalMarks(s.second) << endl;
    }
}
