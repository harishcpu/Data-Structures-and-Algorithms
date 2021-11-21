public class reverseNNodes {
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
	
    public Node reverseNodes(Node temp, int k) {
		if(temp == null)
			return null;
		Node curr = temp;
		Node next = null, prev = null;
		int count = 0;
		while(curr != null && count < k) {
			next = curr.next;
			curr.next = prev;
			prev = curr;
			curr = next;
			count++;
		}
		
		if(next != null)
			temp.next = reverseNodes(next, k);
		
		return prev;
	}	
	public static void main(String args[]) {
		reverseNNodes llist = new reverseNNodes();
		llist.push(15);
		llist.push(14);
		llist.push(13);
		llist.push(12);
		llist.push(11);
		llist.printList(llist.head);
		llist.head = llist.reverseNodes(llist.head, 3);
		llist.printList(llist.head);
	}
}
