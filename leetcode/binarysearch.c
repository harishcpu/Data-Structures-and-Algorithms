#include <stdio.h>

int search(int* nums, int numsSize, int target){
    int left, right, mid;
    left = 0;
    right = numsSize-1;
    while(left <= right) {
        mid = (left + right) / 2;
        if(nums[mid] == target) return mid;
        nums[mid] < target ? (left = mid + 1) : (right = mid - 1);
    }
    return -1;
}

int main(int argc, char *argv[]) {
	int arr[] = {-1, 0, 3, 5, 9, 12};
	for(int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nElement 9 found at index: %d\n", search(arr, 6, 9));
	printf("Element 2 not found: %d\n", search(arr, 6, 2));
	return 0;
}
