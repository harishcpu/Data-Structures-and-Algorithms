public class nthnodefromlast {
	class Node {
		int data;
		Node next;
		Node(int d) {data = d; next = null;}
	}

	Node head;

	public void push(int data) {
		Node newNode = new Node(data);
		if(head == null) {
			head = newNode;
			return;
		}
		newNode.next = head;
		head = newNode;
	}

	public void printList() {
		Node temp = head;
		while(temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}

	public void getnthlastIterative(int n){
		Node temp = head;
		int count = 0;
		while(temp != null) {
			++count;
			temp = temp.next;
		}
		temp = head;
		for(int i = 0; i < count - n; ++i) {
			temp = temp.next;
		}
		System.out.println(temp.data);
	}

		int count = 0;
	public void getnthlastRecursive(Node temp, int n) {
		if(temp == null)
			return;
		getnthlastRecursive(temp.next, n);

		if(++count == n)
			System.out.println(temp.data);
	}

	public static void main(String args[]) {
		nthnodefromlast llist = new nthnodefromlast();
		llist.push(15);
		llist.push(14);
		llist.push(13);
		llist.push(12);
		llist.push(11);
		llist.printList();
		System.out.print("getnthlastIterative: Element present at position 3 from last: ");
		llist.getnthlastIterative(3);
		System.out.print("getnthlastRecursive: Element present at position 3 from last: ");
		llist.getnthlastRecursive(llist.head, 3);
	}
}
