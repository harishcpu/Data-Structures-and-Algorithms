#include <stdio.h>

/* working solution: time limit exceeded error */
void rotate(int *arr, int n, int d) {
	int temp, k;
	n = n - 1;
    for(int i = d; i > 0; i--) {
        temp = arr[n];
        k = n;
        while(k > 0) {
            arr[k] = arr[k-1];
            --k;
        }
        arr[k] = temp;
    }
}

void reverse(int *arr, int i, int j) {
    int temp;
    while(i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        ++i;
        --j;
    }
}
/* accepted solution */
void rotate1(int* arr, int n, int d) {
    reverse(arr, 0, n-d-1);
    reverse(arr, n-d, n-1);
    reverse(arr, 0, n-1);
}

int main(int argc, char *argv[]) {
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	for(int i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	rotate1(arr, 7, 3);

	for(int i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
