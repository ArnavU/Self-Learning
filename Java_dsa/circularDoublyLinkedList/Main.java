package circularDoublyLinkedList;

public class Main {
    public static void main(String[] args) {

		CDoublyLinkedList list = new CDoublyLinkedList();
		
		// list.addFirst(30);
		// list.addFirst(20);
		// list.addFirst(10);
		
		list.addLast(10);
		list.addLast(20);
		list.addLast(30);
		list.addLast(40);
		list.addLast(50);
		
		// list.deleteFirst();
		// list.deleteLast();

        list.addPosition(25, 3);
        list.addPosition(5, 1);
        list.addPosition(100, -1);
        list.addPosition(100, 8);
        list.deleteLast();
        list.addFirst(-10);
		
		list.fDisplay();
		list.bDisplay();
	}
}
