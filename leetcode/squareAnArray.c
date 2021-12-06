#include <stdio.h>

/* Step 1: Divide array into two: negative and positive
 * Step 2: Square each element and use merge sort to store the elements. 
 **/

/* Solution is incomplete */
int square(int *arr, int n) {

	int i =  n/2;
	int j = i + 1;
	int idx = 0;
	
	int temp[6] = {-1};
	while (i >= 0 && j <= n) {
		if (arr[i] * arr[i] < arr[j] * arr[j]) {
			temp[idx++] = arr[i] * arr[i];
			--i;
		} else {
			temp[idx++] = arr[j] * arr[j];
			++j;
		}
	}
	
	while(i >= 0) {
		temp[idx++] = arr[i] * arr[i];
		i--;
	}
	
	while(j < n) {
		temp[idx++] = arr[j] * arr[j];
		j++;
	}


	idx = 0;
	while(idx < n) {
		arr[idx] = temp[idx];
		++idx;
	}

	return 0;
}

int main(int argc, char *argv[]) {
	int arr[] = {-1, 0, 3, 5, 9, 12};
	for(int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	square(arr, 6);

	for(int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
