 

/*
1) add first
2) add last
3) delete first
4) delete last
5) add position
6) delete position 
7) display
*/

public class Main {
    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        ll.addFirst(40);
        ll.addFirst(30);
        ll.addFirst(20);
        ll.addFirst(10);
    
        ll.addLast(50);

        // ll.deleteFirst();
        // ll.deleteLast();

        // ll.addPosition(4, 100);
        // ll.addPosition(100, 100);
        // ll.addPosition(-10, 100);

        ll.deletePosition(-1);
        ll.deletePosition(5);
        ll.deletePosition(99);

        ll.display();
    }
}