public class pairwiseSwap {
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

	public Node swapNodes(Node head, int n) {
		if(head == null)
			return null;
		Node curr = head;
		Node next = head.next;
		Node prev = null;
		while(curr != null && curr.next != null) {
			Node temp = next.next;
			
			if(prev == null)
				head = next;
			else
				prev.next = next;

			next.next = curr;
			curr.next = temp;
			
			prev = curr;
			curr = curr.next;
			if(curr != null)
				next = curr.next;
		}
		return head;
	}

	public static void main(String args[]) {
		pairwiseSwap llist = new pairwiseSwap();
		llist.push(1);
		llist.push(2);
		llist.push(3);
		llist.push(4);
		llist.push(5);
		llist.push(6);
		llist.printList(llist.head);
		llist.head = llist.swapNodes(llist.head, 2);
		llist.printList(llist.head);
	}
}
