#include<iostream>
#include<vector>
using namespace std;

void print_array(vector<int> a) {
	for(int x : a) {
		cout << x << " ";
	}
	cout << endl;
}

// helper method
void merge(vector<int> &a, int start, int end) {
	int i = start;
	int mid = (start+end)/2;
	int j = mid+1;
	vector<int> temp;
	
	while(i <= mid and j <= end) {
		if(a[i] < a[j]) {
			temp.push_back(a[i]);
			i++;
		} else {
			temp.push_back(a[j]);
			j++;
		}
	}
	
	// copy the left over elements from first array
	while(i <= mid) {
		temp.push_back(a[i]);
		i++;
	}
	// copy the left over elements from second array
	while(j <= end) {
		temp.push_back(a[j]);
		j++;
	}
	
	// copy elements back from temp to original array
	int k = 0;
	for (int idx = start; idx <= end; idx++) {
		a[idx] = temp[k++];
	}
	return;
}

// sorting method
void mergesort(vector<int>& a, int start, int end) {
	// base case
	if (start >= end) {
		return;
	}
	
	// recursive case
	int mid = (start+end)/2;
	mergesort(a, start, mid);
	mergesort(a, mid+1, end);
	return merge(a, start, end);
}

int main(void) {
	vector<int> a{10, 5, 2, 0, 7, 6, 4};
	
	int s = 0;
	int e = a.size()-1;
	mergesort(a, s, e);
    print_array(a);

    return 0;
}
