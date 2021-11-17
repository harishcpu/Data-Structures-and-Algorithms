public class countNodes {
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

	public int countRecursive(Node temp) {
		if(temp == null)
			return 0;
		int n = countRecursive(temp.next);
		n = n+1;
		return n;
	}

	public int countIterative(Node temp) {
		int n = 0;
		while(temp != null) {
			n = n+1;
			temp = temp.next;
		}
		return n;
	}

	public void printList() {
		Node temp = head;
		while(temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
	}

	public static void main(String args[]) {
		countNodes llist = new countNodes();
		llist.push(15);
		llist.push(14);
		llist.push(13);
		llist.push(12);
		llist.push(11);
		System.out.println("total nodes in the linked list(Recursive): " + llist.countRecursive(llist.head));
		System.out.println("total nodes in the linked list(Iterative): " + llist.countIterative(llist.head));
		llist.printList();
		System.out.println();
	}
}
