public class countNode {
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

	public int countIterative(Node temp, int key) {
		int frequency = 0;
		while(temp != null) {
			if(temp.data == key)
				++frequency;
			temp = temp.next;
		}
		return frequency;
	}
	
	public int countRecursive(Node temp, int key) {
		if(temp == null)
			return 0;
		if(temp.data == key)
			return 1 + countRecursive(temp.next, key);
		return countRecursive(temp.next, key);
	}
	public static void main(String args[]) {
		countNode llist = new countNode();
		llist.push(17);
		llist.push(16);
		llist.push(11);
		llist.push(14);
		llist.push(11);
		llist.push(12);
		llist.push(11);
		llist.printList();
		System.out.println("(Iterative)The frequency of node 11 is: " + llist.countIterative(llist.head, 11));
		System.out.println("(Recursive)The frequency of node 11 is: " + llist.countRecursive(llist.head, 11));
	}
}
