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

	Node curr = null;
	Node next = null;
	Node prev = null;
	public Node reverse(int n, boolean iter) {
		Node first = curr;
		
		System.out.println("On entering: \ncurr" + curr.data);
		if(prev != null)
			System.out.println("prev " + prev.data);
		else
			System.out.println("prev : null");
		if(next != null)
			System.out.println("next " + curr.data);
		else
			System.out.println("next : null");
		while(n-- != 0 && curr != null) {
			next = curr.next;
			curr.next = prev;
			prev = curr;
			curr = next;
		}
		if(iter)
			first.next = next;
		System.out.println("On exiting: \ncurr" + curr.data);
		System.out.println("prev " + prev.data);
		System.out.println("next " + curr.data);
		return prev;
	}

	public Node reverseNodes(Node temp, int n) {
		curr = temp;
		boolean iter = true;
		while(curr != null && curr.next != null) {
			if(iter) {
				temp = reverse(n, true);
				curr = temp.next;
				iter = false;
		System.out.println("Back: \ncurr" + curr.data);
		System.out.println("prev " + prev.data);
		System.out.println("next " + curr.data);
				printList(temp);
			} else {
				curr = reverse(n, false);
				curr = null;
			}
		}
		curr.next = null;
		return temp;
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
