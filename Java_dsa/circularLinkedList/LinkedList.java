package circularLinkedList;

public class LinkedList {
    static class Node {
        private int data;
        private Node next;
        public Node(int value) {
            this.data = value;
            this.next = null;
        }
    }
    Node head, tail;
    public LinkedList() {
        this.head = null;
        this.tail = null;
    }

    // 1) isEmpty()
    public boolean isEmpty() {
        return head == null;
    }
    // 2) add first
    public void addFirst(int value) {
        Node newNode = new Node(value);
        if(head == null) {
            head = tail = newNode;
            head.next = tail;
        } else {
            tail.next = newNode;
            newNode.next = head;
            head = newNode;
        }
    }
    // 3) add last
    public void addLast(int value) {
        Node newNode = new Node(value);
        if(head == null) {
            head = tail = newNode;
            head.next = tail;
        } else {
            tail.next = newNode;
            newNode.next = head;
            tail = newNode;
        }
    } 
    // 4) delete first
    public void deleteFirst() {
        if(head==tail) 
            head = tail = null;
        else {
            tail.next = head.next;
            head = head.next;
        }
    }
    // 5) delete last
    public void deleteLast() {
        if(head==null || head==tail) {
            head = tail = null;
        } else {
            Node trav = head;
            while(trav.next!=tail) {
                trav = trav.next;
            }
            trav.next = head;
            tail = trav;
        }
    }
    // 6) display
    public void display() {
        Node trav = head;
        if(trav==null) {
            System.out.println("List is empty!!!");
            return;
        }
        System.out.print("Circular list :: ");
        do {
            System.out.print(trav.data + " ");
            trav = trav.next;
        } while(trav != head);
    }
    // 7) delete all
    public void deleteAll() {
        this.head = this.tail = null;
    }
}
