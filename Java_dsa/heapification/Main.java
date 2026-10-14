package heapification;

import java.util.Arrays;

public class Main {
    public static int getKthLargestElement(Heap h, int k) {
        h.heapify();
        int kthMax = -1;
        while(k--!=0) {
            kthMax = h.deleteHeap();
        }
        return kthMax;
    }
    public static void main(String[] args) {
        int[] arr = {0, 6, 14, 3, 26, 8, 18, 21, 9, 5};

        Heap h = new Heap(arr);
        // System.out.println("Array before heap sort :: " + Arrays.toString(arr));
        // h.heapSort();
        // System.out.println("Array after heap sort :: " + Arrays.toString(arr));
        
        int k = 3;
        int kthLargest = getKthLargestElement(h, k);
        System.out.println(String.format("%d(th/rd) element is : %d", k, kthLargest));
    }
}
