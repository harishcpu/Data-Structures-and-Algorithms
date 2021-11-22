public class deleteNode {
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

	public void printList(Node temp) {
		while(temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}
	
	public void deleteNodeInList(int key) {
		Node temp = head;
		if(key == head.data) {
			head = head.next;
			return;
		}
	
		Node prev = null;
		while(temp != null && temp.data != key) {
			prev = temp;
			temp = temp.next;
		}
		if(temp == null)
			return;
		prev.next = temp.next;
	}
	public static void main(String args[]) {
		deleteNode llist = new deleteNode();
		llist.push(11);
		llist.push(12);
		llist.push(13);
		llist.push(12);
		llist.push(11);
		llist.printList(llist.head);
		llist.deleteNodeInList(11);
		llist.deleteNodeInList(13);
		llist.deleteNodeInList(11);
		llist.printList(llist.head);
	}
}
