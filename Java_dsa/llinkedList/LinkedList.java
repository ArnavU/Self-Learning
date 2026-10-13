
public class LinkedList {
    static class Node {
        private int data;
        private Node next;

        public Node(int value) {
            this.data = value;
            this.next = null;
        }
    }
    Node head;
    public LinkedList() {
        head = null;
    }

    // 1) add first
    public void addFirst(int value) {
        Node newNode = new Node(value);
        newNode.next = head;
        head = newNode;
    }

    // 2) add last
    public void addLast(int value) {
        Node newNode = new Node(value);
        if(head == null) {
            head = newNode;
        } else {
            Node trav = head;
            while(trav.next != null) {
                trav = trav.next;
            }
            trav.next = newNode;
        }
    }

    // 3) delete First 
    public void deleteFirst() {
        if(head!=null) head = head.next;
    }

    // 4) delete last
    public void deleteLast() {
        if(head == null || head.next == null) head = null;
        else {
            Node trav = head;
            while(trav.next.next != null) {
                trav = trav.next;
            }
            trav.next = null;
        }
    }

    // 5) add position
    public void addPosition(int pos, int value) {
        Node newNode = new Node(value);
        if(head==null) 
            head = newNode;
        else if(pos<=1) {
            newNode.next = head;
            head = newNode;
        } else {
            Node trav = head;
            for(int i=1; i<pos-1 && trav.next!=null; i++) {
                trav = trav.next;
            }
            newNode.next = trav.next;
            trav.next = newNode;
        }               
    }

    // 6) delete posiition
    public void deletePosition(int pos) {
        if(head==null || pos<1) 
            return;
        else if(pos==1) 
            head = head.next;
        else {
            Node trav = head;
            for(int i=1; i<pos-1; i++) {
                trav = trav.next;
                if(trav.next==null)
                    return;
            }
            trav.next = trav.next.next;
        }
    }

    // 7) display
    public void display() {
        Node trav = head;
        System.out.print("List :: ");
        while(trav!=null) {
            System.out.print(trav.data + " ");
            trav = trav.next;
        }
    }
}