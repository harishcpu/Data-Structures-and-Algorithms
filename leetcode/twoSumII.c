/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i, j;
    j = numbersSize-1;
    i = 0;
    
    if(numbersSize == 0 || numbers == NULL)
        return NULL;
    
    while(numbers[j] > target)	j--;
    
    int k;
    while(i < j) {
        k = j;
        while(i < k) {
            if(target - numbers[k] == numbers[i])
                break;
            k--;
        }
        
		if(i >= k)
			i++;
		else
			break;
    }
    
    if(i >= j)
        return NULL;
    
    int *idx = (int *)malloc(sizeof(int) * 2);
    idx[0] = i;
    idx[1] = j;
    
    *returnSize = 2;
    
    return idx;
}

int main(int argc, char *argv[]) {
	int arr[] = {2, 7, 11, 15};
	for(int i = 0; i < 4; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	int returnSize;

	int *ptr = twoSum(arr, 4, 9, &returnSize);

	for(int i = 0; i < returnSize; i++) {
		printf("%d ", ptr[i]);
	}
	printf("\n");
	return 0;
}
