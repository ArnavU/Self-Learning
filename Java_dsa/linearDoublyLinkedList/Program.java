package linearDoublyLinkedList;

public class Program {
    public static void main(String[] args) {
		DoublyLinkedList l1 = new DoublyLinkedList();
		
		l1.addFirst(20);
		l1.addFirst(10);
		l1.addLast(30);
		l1.addLast(40);
		
		// l1.addPosition(100, 3);
		// l1.addPosition(100, 1);
		// l1.addPosition(100, 5);
		// l1.addPosition(100, 0);
		//l1.addPosition(100, 8);
		
		// l1.deleteFirst();
		// l1.deleteLast();
		
		// l1.deletePosition(3);
		//l1.deletePosition(1);
		//l1.deletePosition(4);
		//l1.deletePosition(-1);
		l1.deletePosition(9);
		
		l1.forwardDisplay();
		l1.backwardDisplay();
		System.out.println("Size = " + l1.size());
		
		l1.deleteAll();
    }
}