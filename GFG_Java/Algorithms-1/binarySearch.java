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
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

	public static void main(String args[]) {
		binarySearch binsrch = new binarySearch();
		//int arr[] = {-1, 0, 3, 5, 9, 12};
		int arr[] = {5};
		binsrch.printArray(arr, 1);
		int rv = binsrch.search(arr, 5);
		if(rv == -1) {
			System.out.println("Target not found");
		} else {
			System.out.println("Target " + arr[rv] + " is found at index " + rv);
		}
	}
}
