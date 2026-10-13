import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Queue q = new Queue(5);
        int choice;
        Scanner sc = new Scanner(System.in);

        do {
            choice = sc.nextInt();
            switch(choice) {
                case 1: // push
                    System.out.println("Enter the element to offer: ");
                    int ele = sc.nextInt();
                    q.offer(ele);
                    break;
                case 2: // peek
                    System.out.println("The front element is : " + q.peek());
                    break;
                case 3: // poll
                    System.out.println("The polled element is: " + q.poll());
                    break;
            }
        } while(choice != 0);
    }
}