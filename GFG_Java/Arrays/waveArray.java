/*
 * wave array
 */
public class waveArray {

	public void convertToWave(int arr[], int n) {
		n = (n % 2 == 1) ? n-1 : n;
		for(int i = 0; i < n; i = i+2) {
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}

	public void printArray(int arr[], int n) {
		for(int i = 0; i < n; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
	public static void main(String args[]) {
		waveArray rotate = new waveArray();
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
		rotate.printArray(arr, 11);
		rotate.convertToWave(arr, 11);
		rotate.printArray(arr, 11);
	}
}
