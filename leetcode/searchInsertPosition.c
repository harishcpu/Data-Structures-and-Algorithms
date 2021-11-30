#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int left, right, mid;
    left = 0;
    right = numsSize;
    while(left < right) {
        mid = left + (right - left) / 2;
        if(nums[mid] > target) {
            right = mid - 1;
            if(nums[right] < target)
                return mid-1;
        } else if (nums[mid] < target) {
            left = mid + 1;
            if(nums[left] > target)
                return mid+1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
	int n[] = {1, 3, 5, 6};
	printf("%d\n", searchInsert(n, 4, 7));
	return 0;
}
