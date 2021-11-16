public class linkedList {
    class Node {
        int data;
        Node next;
        Node(int d) { data = d; next = null; }
    }
    
    Node head;
    
    public void push(int data) {
        // newNode node becomes head
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }
    
    public void append(int data) {
        Node newNode = new Node(data);
        newNode.next = null;
        // if the list is empty
        if(head == null) {
            head = newNode;
            return;
        }
        
        // if the list is not empty
        Node last = head;
        while(last.next != null)
            last = last.next;
        last.next = newNode;
    }
    public void insertAfter(Node prevNode, int data) {
        if(prevNode == null) {
            System.out.println("The given previous node cannot be null.");
            return;
        }
        
        Node newNode = new Node(data);
        newNode.next = prevNode.next;
        prevNode.next = newNode;
    }
    
    public void printList() {
        Node temp = head;
        while(temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }
    
    public static void main(String args[]) {
        linkedList llist = new linkedList();
        
        llist.push(5);
        llist.push(4);
        llist.append(6);
        llist.push(1);
        llist.insertAfter(llist.head.next, 10);
        llist.printList();
    }
}
