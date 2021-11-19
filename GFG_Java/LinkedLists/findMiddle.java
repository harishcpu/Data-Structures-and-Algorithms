public class findMiddle {
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

	public void printMiddle() {
		Node mid = head;
		int count = 0;
		while(head != null) {
			if((count % 2) == 1)
				mid = mid.next;
			++count;
			head = head.next;
		}
		System.out.println(mid.data);
	}

	public static void main(String args[]) {
		findMiddle llist = new findMiddle();
		llist.push(17);
		llist.push(16);
		llist.push(15);
		llist.push(14);
		llist.push(13);
		llist.push(12);
		llist.push(11);
		llist.printList();
		System.out.print("The middle node is: ");
		llist.printMiddle();
	}
}
