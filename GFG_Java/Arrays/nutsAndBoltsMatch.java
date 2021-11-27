/*
 * nutsAndBoltsMatch: O(nlogn)
 */
/* ERROR: Array index out of bounds exception at line 57 */
public class nutsAndBoltsMatch
{
	public static void main(String args[]) {
		nutsAndBoltsMatch obj = new nutsAndBoltsMatch();
		char nuts[] = {'@','%','$','#','^'};
		char bolts[] = {'%','@','#','$','^'};

		obj.printNutsAndBolts(nuts, bolts, 5);
		obj.matchPairs(nuts, bolts, 0, 4);
		obj.printNutsAndBolts(nuts, bolts, 5);
	}

	public void printNutsAndBolts(char nuts[], char bolts[], int n) {
		int i = 0;
		System.out.print("Nuts: ");
		while(i < n) {
			System.out.print(nuts[i] + " ");
			++i;
		}
		System.out.println();
		
		i = 0;
		System.out.print("Bolts: ");
		while(i < n) {
			System.out.print(bolts[i] + " ");
			++i;
		}
		System.out.println();
	}
	
	public int partition(char arr[], int low, int high, char pi) {
		int i, j;
	    char temp;
		i = low;
			for(j = low; j < high; j++) {
				if(arr[j] < pi) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					++i;
				} else if(arr[j] == pi) {
					temp = arr[high];
					arr[high] = arr[j];
					arr[j] = temp;
				}
			}
			temp = arr[i];
			arr[i] = arr[high];
			arr[high] = temp;
			return i;
	}

	public void matchPairs(char nuts[], char bolts[], int low, int high) {
		int pi = partition(nuts, low, high, bolts[high]);
		partition(bolts, low, high, nuts[high]);

		matchPairs(nuts, bolts, low, pi-1);
		matchPairs(nuts, bolts, pi+1, high);
	}
}
