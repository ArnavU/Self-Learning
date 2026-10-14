package priorityQueue;

public class Heap {
    private int[] arr;
    private int SIZE;

    public Heap(int length) {
        arr = new int[length+1];
        SIZE = 0;
    }
    public boolean isEmpty() {
        return SIZE==0;
    }
    public boolean isFull() {
        return SIZE==arr.length-1;
    }
    // 1. getMax
    public int getMax() {
        return arr[1];
    }
    // 2. deleteHeap
    public int deleteHeap() {
        if(isEmpty()) {
            System.out.println("Heap is empty!!!");
            return -1;
        } 
        int backup = arr[1];
        arr[1] = arr[SIZE];
        SIZE--;
        int pi = 1;
        int ci = pi*2;
        while(ci<=SIZE) {
            if((ci+1<=SIZE) && arr[ci+1]>arr[ci]) 
                ci = ci+1;
            if(arr[ci]>arr[pi]) {
                int temp = arr[pi];
                arr[pi] = arr[ci];
                arr[ci] = temp;
            } else 
                break;
            pi = ci;
            ci = ci*2;
        }
        return backup;
    } 
    // 3. addHeap
    public void addHeap2(int val) {
        if(isFull()) {
            System.out.println("Heap is full!!!");
            return;
        }
        SIZE++;
        arr[SIZE] = val;
        int temp = arr[SIZE];
        int pi=SIZE;
        for(; arr[pi/2]<temp && pi/2>=1; pi/=2) {
            arr[pi] = arr[pi/2];
        }
        arr[pi] = temp;
    }
    // 4. addHeap
    public void addHeap(int val) {
        if(isFull()) {
            System.out.println("Heap is full!!!");
            return;
        }
        SIZE++;
        arr[SIZE] = val;
        int ci = SIZE;
        int pi = ci/2;
        while(pi>=1) {
            if(arr[pi]>arr[ci]) 
                break;
            int temp = arr[pi];
            arr[pi] = arr[ci];
            arr[ci] = temp;
            ci = pi;
            pi = ci/2;
        }
    }

    public void printHeap() {
        System.out.println("Printing heap:: ");
        for(int i=1; i<=SIZE; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}

