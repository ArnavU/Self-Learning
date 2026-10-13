package circularLinkedList;

public class Main {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
		
		list.addLast(50);
		list.addLast(40);
		list.addLast(30);
		list.addFirst(20);
		list.addFirst(10);
		
		// list.deleteFirst();
		// list.deleteLast();
		// list.deleteLast();
		// list.deleteLast();
		// list.deleteLast();
		// list.deleteLast();
		
		list.display();
    }
}
