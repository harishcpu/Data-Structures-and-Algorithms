public class reverseList {
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

	public Node reverseListIterative(Node head) {
		Node currNode = head;
		Node nextNode = null;
		Node prevNode = null;
		while(currNode != null) {
			nextNode = currNode.next;
			currNode.next = prevNode;
			prevNode = currNode;
			currNode = nextNode;
		}
		head = prevNode;
		return head;
	}
	
	public static void main(String args[]) {
		reverseList llist = new reverseList();
		llist.push(15);
		llist.push(14);
		llist.push(13);
		llist.push(12);
		llist.push(11);
		llist.printList();
		llist.head = llist.reverseListIterative(llist.head);
		System.out.println("(Iterative)The list after reversing: ");
		llist.printList();
	}
}
