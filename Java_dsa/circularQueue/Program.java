package circularQueue;
import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        int choice;
        Scanner sc = new Scanner(System.in);
        Queue q = new Queue(4);

        do {
            System.out.println("Enter your choice: \n1. Offer \n2. Peek \n3. Poll");
            choice = sc.nextInt();
            switch(choice) {
                case 1: // offer
                    System.out.println("Enter the value to offer: ");
                    int ele = sc.nextInt();
                    q.offer(ele);
                    break;
                case 2: // peek
                    System.out.println("The peeked element is: " + q.peek());
                    break;
                case 3: // poll
                    System.out.println("The polled element is: " + q.poll());
                    break;
            }
        } while(choice != 0);
    }
}
