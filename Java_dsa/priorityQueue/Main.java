package priorityQueue;

public class Main {
    public static void main(String[] args) {
        // Heap h = new Heap(10);
        // h.addHeap(6);
        // h.addHeap(14);
        // h.addHeap(3);
        // h.addHeap(26);
        // h.addHeap(8);

        // // h.printHeap();

        // while(!h.isEmpty()) {
        //     System.out.println(h.deleteHeap());
        // }

        PriorityQueue pq = new PriorityQueue(10);
        pq.offer(6);
        pq.offer(14);
        pq.offer(3);
        pq.offer(26);
        pq.offer(8);

        System.out.println("Priority queue:: ");
        while(!pq.isEmpty()) 
            System.out.println(pq.poll());
    }
}
