import java.util.ArrayDeque;
import java.util.Queue;

public class Program_07_Collections_Queue {
    public static void main(String[] args) {
		Queue<String> q = new ArrayDeque<String>( );
		q.offer("One");
		q.add("Two");
		q.add("Three");
		q.offer("Four");
		System.out.println("Top most ele : " + q.peek());
		while(!q.isEmpty()) {
			String ele = q.remove(); 
		}
		// System.out.println("Removing element from empty queue : " + q.element());
        // NoSuchElementException
    }
}
