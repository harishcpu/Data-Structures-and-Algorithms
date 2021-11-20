public class detectLoop {
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

	public boolean detectLoopInList(Node temp) {
		Node fast, slow;
		fast = slow = temp;
		while(fast.next != null) {
			fast = fast.next.next;
			slow = slow.next;
			if(fast == slow)
					return true;
		}
		return false;
	}

	public static void main(String args[]) {
		detectLoop llist = new detectLoop();
		llist.push(15);
		llist.push(14);
		llist.push(13);
		llist.push(12);
		llist.push(11);
		llist.printList();
		if(llist.detectLoopInList(llist.head))
				System.out.println("loop detected");
		else
				System.out.println("loop not detected");
		llist.head.next.next = llist.head;
		if(llist.detectLoopInList(llist.head))
				System.out.println("loop detected");
		else
				System.out.println("loop not detected");
	}
}
