package heapification;

public class Heap {
    private int[] arr;
    private int SIZE;

    public Heap(int[] arr) {
        this.arr = arr;
        SIZE = arr.length-1;
    }

    public void heapify() {
        for(int i=SIZE/2; i>=1; i--) {
            int pi = i;
            int ci = pi*2;

            while(ci<=SIZE) {
                if((ci+1<SIZE) && arr[ci+1]>arr[ci])
                    ci = ci+1;
                if(arr[pi] > arr[ci])
                    break;
                int temp = arr[ci];
                arr[ci] = arr[pi];
                arr[pi] = temp;
                pi = ci;
                ci = ci*2;
            }
        }
    }

    public int deleteHeap() {
        int max = arr[1];
        arr[1] = arr[SIZE];
        SIZE--;
        int pi = 1;
        int ci = pi*2;
        while(ci<=SIZE) {
            if(ci+1<=SIZE && arr[ci+1]>arr[ci])
                ci = ci+1;
            if(arr[pi] > arr[ci])
                break;
            int temp = arr[pi];
            arr[pi] = arr[ci];
            arr[ci] = temp;
            pi = ci;
            ci = ci*2;
        }
        return max;
    }

    public void heapSort() {
        heapify();
        for(int i=arr.length-1; i>=1; i--) {
            arr[i] = deleteHeap();
        }
    }
}
