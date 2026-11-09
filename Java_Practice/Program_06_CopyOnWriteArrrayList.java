import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.Iterator;

public class Program_06_CopyOnWriteArrrayList {
    // fail-fast and fail-safe iterators
    public static void main(String[] args) {
		List<Integer> list = new CopyOnWriteArrayList<>();  
		Collections.addAll(list, 10,20,30,40,50);
		
		Iterator<Integer> trav = list.iterator(); 
		while(trav.hasNext()) {
			Integer ele = trav.next(); 
			System.out.println(ele);
			if(ele == 30)
			  list.add(3, 33);	
		}
		System.out.println("Updated list");
		trav = list.iterator(); 
		while(trav.hasNext()) {
			Integer ele = trav.next(); 
			System.out.println(ele);
			if(ele == 30)
			  list.add(3, 33);	
		}
        System.out.println("Updated list: ");
        System.out.println(list);
	}

    public static void main1(String[] args) {
		List<Integer> list = new ArrayList<>(); 
		Collections.addAll(list, 10,20,30,40,50);
		
		Iterator<Integer> trav = list.iterator(); 
		while(trav.hasNext()) {
			Integer ele = trav.next(); 
			System.out.println(ele);
			if(ele == 30)
			  list.add(3, 33);	// ConcurrentModificationException
		}
	}
}
