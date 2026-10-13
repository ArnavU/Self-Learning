package linearDoublyLinkedList;

public class DoublyLinkedList {
    static class Node {
        private int data;
        private Node next, prev;

        public Node(int value) {
            this.data = value;
            next = prev = null;
        }
    }    

    private Node head, tail;
    private int size;

    public DoublyLinkedList() {
        this.head = this.tail = null;
        this.size = 0;
    }

    // 1) isEmpty
    public boolean isEmpty() { return size==0; }
    
    // 2) forward display
    public void forwardDisplay() {
        if(head==null) {
            System.out.println("List is empty!!!");
            return;
        }
        System.out.print("Forward List :: ");
        Node trav = head;
        while(trav!=null) {
            System.out.print(trav.data + " ");
            trav = trav.next;
        }
        System.out.println();
    }
    
    // 3) backward display
    public void backwardDisplay() {
        if(head == null) {
            System.out.println("List is empty!!!");
            return;
        }
        System.out.print("Reversed List :: ");
        Node trav = tail;
        while(trav!=null) {
            System.out.print(tail.data + " ");
            trav = trav.prev;
        }
        System.out.println();
    } 

    // 4) add first
    public void addFirst(int value) {
        Node newNode = new Node(value);
        if(head==null) 
            head = tail = newNode;
        else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        size++;
    }

    // 5) add last
    public void addLast(int value) {
        Node newNode = new Node(value);
        if(head == null) 
            head = tail = newNode;
        else {
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }

    // 6) add position
    public void addPosition(int value, int pos) {
        Node newNode = new Node(value);
        if(pos<1 || pos > size+1) 
            return;
        else if(pos==1) {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        } else if(pos==size+1) {
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
        } else {
            Node trav = head;
            for(int i=1; i<pos-1; i++) 
                trav = trav.next;
            newNode.next = trav.next;
            newNode.prev = trav;
            trav.next.prev = newNode;
            trav.next = newNode;
        }
        size++;
    }

    // 7) delete first
    public void deleteFirst() {
        if(head == null) 
            return;
        else if(head==tail)
            head = tail = null;
        else {
            head = head.next;
            head.prev = null;
        }
        size--;
    }

    // 8) delete last
    public void deleteLast() {
        if(head==null)
            return;
        else if(head == tail) 
            head = tail = null;
        else {
            tail = tail.prev;
            tail.next = null;
        }
        size--;
    }

    // 9) delete position 
    public void deletePosition(int pos) {
        if(pos<1 || pos>size)
            return;
        else if(pos==1) {
            head = head.next;
            head.prev = null;
        } else if(pos==size) {
            tail = tail.prev;
            tail.next = null;
        } else {
            Node trav = head;
            for(int i=1; i<pos; i++) {
                trav = trav.next;
            }
            trav.prev.next = trav.next;
            trav.next.prev = trav.prev;
        }
        size--;
    }

    // 10) size
    public int size() {
        return size;
    }

    // 11) delete all
    public void deleteAll() {
        head = tail = null;
    }
}
