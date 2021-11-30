#include <stdio.h>

int bv;

int isBadVersion(int ver) {
	if(ver >= bv)
		return 1;
	return 0;
}

/* Time complexity: O(logN)
 */ 
int firstbadversion(int n) {
    int left = 1;
    int right = n;
    int mid;
    while(left < right) {
        mid = left + (right - left) / 2;
        if(isBadVersion(mid))
			right = mid;
        else
			left = mid + 1;
    }
    return left;
}

int main(int argc, char *argv[]) {
	int n;
	scanf("%d %d", &n, &bv);
	printf("%d\n", firstbadversion(n));
	return 0;
}
