public class searchElement {
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

	public boolean search(int element){
		Node temp = head;
		while(temp != null) {
			if(temp.data == element)
					return true;
			temp = temp.next;
		}
		return false;
	}

	public static void main(String args[]) {
		searchElement llist = new searchElement();
		llist.push(15);
		llist.push(14);
		llist.push(13);
		llist.push(12);
		llist.push(11);
		llist.printList();
		if(llist.search(14))
				System.out.println("Element 14 is present in the linked list");
		else
				System.out.println("Element 14 is not present in the linked list");
	}
}
