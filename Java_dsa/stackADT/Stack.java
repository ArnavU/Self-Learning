package stackADT;

public class Stack {
    private final int SIZE;
    private int top;
    private int[] arr;

    public Stack(int size) {
        this.SIZE = size;
        this.arr = new int[SIZE];
        this.top = -1;
    }
    public void push(int ele) {
        if(isFull()) {
            System.out.println("Stack is full!!!");
        } else {
            arr[++top] = ele;
        }
    }
    public int pop() {
        if(isEmpty()) {
            System.out.println("Stack is empty!!!");
            return -1;
        } 
        int temp = this.peek();
        top--;
        return temp;
    }
    public int peek() {
        if(isEmpty()) {
            System.out.println("Stack is empty!!");
            return -1;
        }
        return arr[top];
    }
    public boolean isEmpty() {
        return top == -1;
    }
    public boolean isFull() {
        return top == SIZE-1;
    }
}