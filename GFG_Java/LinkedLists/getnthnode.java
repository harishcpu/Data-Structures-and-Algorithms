public class getnthnode {
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

	public Node getnthnodeIterative(int n){
		Node temp = head;
		int count = 0;
		while(temp != null) {
			if(count == n)
				return temp;
			count++;
			temp = temp.next;
		}
		return null;
	}

	public Node getnthnodeRecursive(Node temp, int n) {
		if(temp == null)
			return null;
		if(n == 0)
			return temp;
		return getnthnodeRecursive(temp.next, n-1);
	}

	public static void main(String args[]) {
		getnthnode llist = new getnthnode();
		llist.push(15);
		llist.push(14);
		llist.push(13);
		llist.push(12);
		llist.push(11);
		llist.printList();
		System.out.println("getnthnodeIterative: Element present at position 3: " + llist.getnthnodeIterative(3).data);
		System.out.println("getnthnodeRecursive: Element present at position 4: " + llist.getnthnodeIterative(4).data);
	}
}
