package circularQueue;

public class Queue {
    private final int SIZE;
    private int front;
    private int rear;
    private int[] arr;

    public Queue(int size) {
        this.SIZE = size;
        this.front = this.rear = -1;
        this.arr = new int[SIZE];
    }
    public void offer(int ele) {
        if(isFull()) {
            System.out.println("Queue is full!!!");
        } else {
            rear = (rear + 1) % SIZE;
            arr[rear] = ele;
        }
    }
    public int peek() {
        if(isEmpty()) {
            System.out.println("Queue is empty!!!");
            return -1;
        }
        return arr[(front+1)%SIZE];
    }
    public int poll() {
        if(isEmpty()) {
            System.out.println("Queue is empty!!!");
            return -1;
        } 
        int temp = arr[(front+1)%SIZE];
        front = (front+1)%SIZE;
        if(front==rear) front = rear = -1;
        return temp;
    }

    public boolean isFull() {
        return (front==rear && rear!=-1) || (front == -1 && rear == SIZE-1);
    }
    public boolean isEmpty() {
        return front==-1 && rear==-1;
    }
}
