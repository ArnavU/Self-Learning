import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class Program_08_Collections_PiorityQueue {
    public static void main(String[] args) {
		//(Elements are retrieved as per priority -- 
		//decided by Comparable (Natural Ordering)
		Queue<String> q = new PriorityQueue<String>( ); 
		q.offer("I");
		q.offer("N");
		q.offer("F");
		q.offer("O");
		
		while(!q.isEmpty()) {
			String ele = q.poll(); 
			System.out.println(ele);
		}

	}
	public static void main1(String[] args) {
		class StringDescComparator implements Comparator<String>{

			@Override
			public int compare(String x, String y) {
				return y.compareTo(x); 
			}
			
		}
		Queue<String> q = new PriorityQueue<String>(new StringDescComparator()); 
		q.offer("I");
		q.offer("N");
		q.offer("F");
		q.offer("O");
		while(!q.isEmpty()) {
			String ele = q.poll(); 
			System.out.println(ele);
		}
	}
}
