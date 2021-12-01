#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int left, right, mid;
    left = 0;
    right = numsSize;
    while(left <= right) {
        mid = left + (right - left) / 2;
        if(nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return left;
}

int main(int argc, char *argv[]) {
	int n[] = {1, 3, 5, 6};
	printf("target 7: %d\n", searchInsert(n, 4, 7));
	printf("target 0: %d\n", searchInsert(n, 4, 0));
	printf("target 2: %d\n", searchInsert(n, 4, 2));
	printf("target 4: %d\n", searchInsert(n, 4, 4));
	return 0;
}
