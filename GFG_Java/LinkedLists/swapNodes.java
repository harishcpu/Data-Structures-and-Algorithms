public class swapNodes {
	class Node {
		int data;
		Node next;
		Node(int d) {
				data = d; 
				next = null; 
		}
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

	public void printList(Node temp) {
		while(temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}

	public void swapNodesByAddress(int a, int b) {
		if(a == b)
			return;

		Node nodeA, nodeB, prevA, prevB;
		prevA = prevB = null;
		nodeA = head;
		while(nodeA != null && nodeA.data != a) {
			prevA = nodeA;
			nodeA = nodeA.next;
		}
		nodeB = head;
		while(nodeB != null && nodeB.data != b) {
			prevB = nodeB;
			nodeB = nodeB.next;
		}

		if(prevA == null) {
			prevB.next = nodeA;
			head = nodeB;
		} else {
			prevA.next = nodeB;
		}

		if(prevB == null) {
			prevA.next = nodeB;
			head = nodeA;
		} else {
			prevB.next = nodeA;
		}

		Node temp = nodeA.next;
		nodeA.next = nodeB.next;
		nodeB.next = temp;
	}

	public static void main(String args[]) {
		swapNodes llist = new swapNodes();
		llist.push(1);
		llist.push(2);
		llist.push(3);
		llist.push(4);
		llist.push(5);
		llist.printList(llist.head);
		llist.swapNodesByAddress(3, 4);
		llist.printList(llist.head);
		llist.swapNodesByAddress(1, 5);
		llist.printList(llist.head);
		llist.swapNodesByAddress(1, 3);
		llist.printList(llist.head);
		llist.swapNodesByAddress(2, 5);
		llist.printList(llist.head);
		System.out.println();
	}
}
