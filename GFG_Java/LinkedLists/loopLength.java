public class loopLength {
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

	public int countNodes(Node temp) {
		int res = 1;
		Node n = temp;
		while(n.next != temp) {
			res++;
			n = n.next;
		}
		return res;
	}

	public int countNodesInLoop(Node temp) {
		Node fast, slow;
		fast = slow = temp;

		while(fast != null && slow != null && fast.next != null) {
			fast = fast.next.next;
			slow = slow.next;
			
			if (slow == fast)
				return countNodes(slow);
		}
		
		int count = 0;
		do {
			slow = slow.next;
			++count;
		} while(fast != slow);
		
		return count;
	}

	public static void main(String args[]) {
		loopLength llist = new loopLength();
		llist.push(15);
		llist.push(14);
		llist.push(13);
		llist.push(12);
		llist.push(11);
		llist.printList();
		llist.head.next.next.next.next.next = llist.head.next.next;
		System.out.println("loop detected. No. of nodes in loop is " + llist.countNodesInLoop(llist.head));
	}
}
