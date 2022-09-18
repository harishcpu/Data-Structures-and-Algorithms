#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &a, int s, int e) {
    int i = s-1;
    int pivot = a[e];
    
    for(int j=s; j < e; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    
    swap(a[i+1], a[e]);
    return i+1;
}

void qsort(vector<int> &a, int s, int e) {
    if(s>=e)
        return;
        
	int p = partition(a, s, e);
	qsort(a, s, p-1);
	qsort(a, p+1, e);
	return;
}

int main(void) {
	vector<int> a{10, 5, 2, 0, 7, 6, 4};

	qsort(a, 0, a.size()-1);

	for(int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
    cout << endl;
	return 0;
}
