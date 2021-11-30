/*
 * Method: Rotate one by one 
 */
public class reverseArray {	
	public void reverse(int[] arr, int start, int end) {
		while(start < end) {
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			start++;
			end--;
		}
	}

	public void printArray(int arr[], int n) {
		for(int i = 0; i < n; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
	public static void main(String args[]) {
		reverseArray rev = new reverseArray();
		int arr[] = {1, 2, 3, 4, 5, 6, 7};
		rev.printArray(arr, 7);
		rev.reverse(arr, 0, 6);
		rev.printArray(arr, 7);
	}
}
