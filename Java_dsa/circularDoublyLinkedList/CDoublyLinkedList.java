package circularDoublyLinkedList;

public class CDoublyLinkedList {
    static class Node {
        private int data;
        private Node next, prev;

        public Node(int value) {
            this.data = value;
            this.next = this.prev = null;
        }
    }
    private Node head;
    public CDoublyLinkedList() {
        this.head = null;
    }

    // 1. add first
    public void addFirst(int value) {
        Node newNode = new Node(value);
        if(head == null) {
            head = newNode;
            head.next = head.prev = head;
        } else {
            newNode.next = head;
            newNode.prev = head.prev;
            head.prev.next = newNode;
            head.prev = newNode;
            head = newNode;
        }
    }

    // 2. add last
    public void addLast(int value) {
        Node newNode = new Node(value);
        if(head == null) {
            head = newNode;
            head.next = head.prev = newNode;
        } else {
            newNode.next = head;
            newNode.prev = head.prev;
            head.prev.next = newNode;
            head.prev = newNode;
        }
    }

    // 3. delete first
    public void deleteFirst() {
        if(head==null)
            return;
        else if(head==head.prev)
            head = null;
        else {
            head.prev.next = head.next;
            head.next.prev = head.prev;
            head = head.next;
        }
    }

    // 4. delete last
    public void deleteLast() {
        if(head == null)
            return;
        else if(head == head.prev) 
            head = null;
        else {
            head.prev.prev.next = head;
            head.prev = head.prev.prev;
        }
    }

    // 5. fDisplay
    public void fDisplay() {
        if(head == null) {
            System.out.println("List is empty!!!");
            return;
        } 
        Node trav = head;
        System.out.print("Forward list :: ");
        do {
            System.out.print(trav.data + " ");
            trav = trav.next;
        } while(trav!=head);
        System.out.println();
    }

    // 6. bDisplay
    public void bDisplay() {
        if(head == null) {
            System.out.println("List is empty!!!");
            return;
        }
        System.out.print("Reverse List :: ");
        Node trav = head.prev;
        do {
            System.out.print(trav.data + " ");
            trav = trav.prev;
        } while(trav != head.prev);
        System.out.println();
    }

    // 7. add position
    public void addPosition(int value, int pos) {
        Node newNode = new Node(value);
        if(pos<1)
            return;
        else if(pos==1) {
            if(head==null) {
                head = newNode;
                head.next = head.prev = newNode;
            } else {
                newNode.prev = head.prev;
                newNode.next = head;
                head.prev.next = newNode;
                head.prev = newNode;
                head = newNode;
            }
        } else {
            Node trav = head;
            for(int i=1; i<pos-1; i++) {
                trav = trav.next;
                if(trav==head)  
                    return;
            }
            newNode.next = trav.next;
            newNode.prev = trav;
            trav.next.prev = newNode;
            trav.next = newNode;
        }
    }
}