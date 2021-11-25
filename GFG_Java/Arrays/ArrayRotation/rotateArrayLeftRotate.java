/*
 * Method: Rotate one by one 
 */
public class rotateArray01 {	

	public void leftRotateByOne(int arr[], int n) {
		int i = 0;
		int temp = arr[i];
		for(i = 0; i < n-1; i++) {
			arr[i] = arr[i+1];
		}
		arr[i] = temp;
	}

	public void leftRotate(int arr[], int d, int n) {
		while(d-- != 0) {
			leftRotateByOne(arr, n);
		}
	}	
	public void printArray(int arr[], int n) {
		for(int i = 0; i < n; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
	public static void main(String args[]) {
		rotateArray01 rotate = new rotateArray01();
		int arr[] = {1, 2, 3, 4, 5, 6, 7};
		rotate.printArray(arr, 7);
		rotate.leftRotate(arr, 2, 7);
		rotate.printArray(arr, 7);
	}
}
