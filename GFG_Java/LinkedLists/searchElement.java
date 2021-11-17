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

	public boolean searchIterative(int element){
		Node temp = head;
		while(temp != null) {
			if(temp.data == element)
					return true;
			temp = temp.next;
		}
		return false;
	}

	public boolean searchRecursive(Node temp, int element) {
		if(temp == null)
				return false;
		if(temp.data == element)
				return true;
		return searchRecursive(temp.next, element);
	}

	public static void main(String args[]) {
		searchElement llist = new searchElement();
		llist.push(15);
		llist.push(14);
		llist.push(13);
		llist.push(12);
		llist.push(11);
		llist.printList();
		if(llist.searchIterative(14))
				System.out.println("SearchIterative: Element 14 is present in the linked list");
		else
				System.out.println("SearchIterative: Element 14 is not present in the linked list");
		
		if(llist.searchRecursive(llist.head, 14))
				System.out.println("SearchRecursive: Element 14 is present in the linked list");
		else
				System.out.println("SearchRecursive: Element 14 is not present in the linked list");
		
		if(llist.searchIterative(16))
				System.out.println("SearchIterative: Element 14 is present in the linked list");
		else
				System.out.println("SearchIterative: Element 14 is not present in the linked list");
		
		if(llist.searchRecursive(llist.head, 16))
				System.out.println("SearchRecursive: Element 14 is present in the linked list");
		else
				System.out.println("SearchRecursive: Element 14 is not present in the linked list");
	}
}
