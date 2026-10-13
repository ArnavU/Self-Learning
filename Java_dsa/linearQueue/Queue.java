
public class Queue {
    private final int SIZE;
    private int front;
    private int rear;
    int[] arr;

    public Queue(int size) {
        this.SIZE = size;
        front = -1;
        rear = -1;
        arr = new int[SIZE];
    }
    public void offer(int ele) {
        if(isFull()) {
            System.out.println("Queeu is full!!!");
        } else {
            rear = rear + 1;
            arr[rear] = ele;
        }
    }
    public int poll() {
        if(isEmpty()) {
            System.out.println("Queue is empty!!!");
            return -1;
        }
        int temp = arr[front+1];
        front = front+1;
        if(front==rear) front = rear = -1;
        return temp;
    }
    public int peek() {
        if(isEmpty()) {
            System.out.println("Queue is empty!!!");
            return -1;
        } 
        return arr[front+1];
    }

    public boolean isEmpty() {
        return rear == -1;
    } 
    public boolean isFull() {
        return rear == SIZE-1;
    }



}