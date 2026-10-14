package priorityQueue;

public class PriorityQueue {
    private final int SIZE;
    private Heap h;
    
    public PriorityQueue(int size) {
        h = new Heap(size);
        SIZE = size;
    }
    public boolean isEmpty() {
        return h.isEmpty();
    }
    public boolean isFull() {
        return h.isFull();
    }
    public int poll() {
        if(h.isEmpty()) {
            System.out.println("Queue is Empty!!!");
            return -1;
        }
        return h.deleteHeap();
    }
    public void offer(int val) {
        if(h.isFull()) {
            System.out.println("Queue is full!!!");
            return;
        }
        h.addHeap(val);
    }
    public int peek() {
        if(h.isEmpty()) {
            System.out.println("Queue is empty!!!");
            return -1;
        }
        return h.getMax();
    }
}
