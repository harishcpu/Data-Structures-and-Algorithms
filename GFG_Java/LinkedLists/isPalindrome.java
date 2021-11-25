public class isPalindrome {
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

	Node left;
	public boolean palindrome(Node right) {
		left = head;
		if(right == null)
			return true;

		boolean ispa = palindrome(right.next);
		if(ispa == false)
			return false;
		
		boolean ispal = (left.data == right.data);
		left = left.next;
		return ispal;
	}

	public Node find_mid(Node head) {
		Node fast = head;
		Node slow = head;

		while(fast != null && fast.next != null) {
			fast = fast.next.next;
			slow = slow.next;
		}
		return slow;
	}

	public boolean palindrome(Node head) {
		// find mid
		Node mid = find_mid(head);
		// reverse half
		reverse(mid.next);
		//comapre nodes
		
	}	
	public static void main(String args[]) {
		isPalindrome llist = new isPalindrome();
		llist.push(11);
		llist.push(12);
		llist.push(13);
		llist.push(12);
		llist.push(11);
		llist.printList(llist.head);
		if(llist.palindrome(llist.head))
			System.out.println("Is palindrome");
		else
			System.out.println("Not a palindrome");
		llist.push(16);
		llist.printList(llist.head);
		if(llist.palindrome(llist.head))
			System.out.println("Is palindrome");
		else
			System.out.println("Not a palindrome");
	}
}
