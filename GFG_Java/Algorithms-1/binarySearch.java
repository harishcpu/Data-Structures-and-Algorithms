/*
 * Method: Rotate one by one 
 */
public class binarySearch {	
	public void printArray(int arr[], int n) {
		for(int i = 0; i < n; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
	
	public int search(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        int mid;
        while(left < right) {
            mid = (left + right) / 2;
            if (arr[mid] < target){
                left = mid + 1;
            } else if (arr[mid] > target) {
                left = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

	public static void main(String args[]) {
		binarySearch binsrch = new binarySearch();
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		binsrch.printArray(arr, 9);
		int rv = binsrch.search(arr, 7);
		if(rv == -1) {
			System.out.println("Target not found");
		} else {
			System.out.println("Target " + arr[rv] + " is found at index " + rv);
		}
	}
}
