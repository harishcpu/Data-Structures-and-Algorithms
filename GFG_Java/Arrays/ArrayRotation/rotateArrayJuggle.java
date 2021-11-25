/*
 * Method: A juggling algorithm 
 */
public class rotateArrayJuggle {

	public void rotate(int arr[], int d, int n) {
		int temp, j, k;
		temp = j = 0;
		for(int i = 0; i < d; i++) {
			temp = arr[i];
			k = i;
			j = i;
			while(j < n & j+d < n) {
				j = j + d;
				arr[k] = arr[j];
				k = j;
			}
			arr[j] = temp;
		}
	}

	public void printArray(int arr[], int n) {
		for(int i = 0; i < n; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
	public static void main(String args[]) {
		rotateArrayJuggle rotate = new rotateArrayJuggle();
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
		rotate.printArray(arr, 12);
		rotate.rotate(arr, 3, 12);
		rotate.printArray(arr, 12);
	}
}
