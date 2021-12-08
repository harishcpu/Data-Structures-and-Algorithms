#include <stdio.h>

/*working solution: time limit exceeded error */
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

int main(int argc, char *argv[]) {
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	for(int i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	rotate(arr, 7, 3);

	for(int i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
