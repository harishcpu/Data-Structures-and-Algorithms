public class linkedListDelete {
	class Node {
		int data;
		Node next;
		Node(int d) { data = d; next = null; }
	}

	Node head;
	
	public void deleteNode(int key) {
		if(head != null && head.data == key) {
			head = head.next;
			return;
		}
		
		Node prevNode = null, temp = head;
		while(temp != null && temp.data != key) {
			prevNode = temp;
			temp = temp.next;
		}
		if(temp == null)
			return;
		prevNode.next = temp.next;
	}

	public void insert(int data) {
		Node newNode = new Node(data);
		newNode.next = head;
		head = newNode;	
	}

	public void printList() {
		if(head == null) {
			System.out.println("List is empty.");
			return;
		}
		Node temp = head;
		while(temp != null){
			System.out.print(temp.data + " ");
			temp = temp.next;	
		}
		System.out.println();
	}
	
	public static void main(String args[]) {
		linkedListDelete llist = new linkedListDelete();
		llist.insert(3);
		llist.insert(2);
		llist.insert(1);
		llist.printList();
		llist.deleteNode(2);
		llist.printList();
		llist.deleteNode(3);
		llist.printList();
		llist.deleteNode(1);
		llist.printList();
	}
}
