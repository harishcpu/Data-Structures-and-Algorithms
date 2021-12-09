#include <stdio.h>

void moveZeroes(int* nums, int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if(nums[i]) {
            nums[j++] = nums[i];
        }
    }
    
    while(j < n) {
        nums[j++] = 0;
    }
}

int main(int argc, char *argv[]) {
	int arr[] = {0, 1, 0, 3, 12};
	for(int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	moveZeroes(arr, 5);

	for(int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
