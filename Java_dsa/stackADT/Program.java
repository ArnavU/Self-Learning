package stackADT;

import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        Stack stk = new Stack(3);
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("Enter your choice: \n1. Push \n2. Peek \n3. Pop");
            choice = sc.nextInt();

            switch(choice) {
                case 1: // push
                    System.out.println("Enter the element to push: "); 
                    int ele = sc.nextInt();
                    stk.push(ele);
                    break;
                case 2: // peek
                    System.out.println("The peeked element is: " + stk.peek());
                    break;
                case 3: // pop
                    System.out.println("The popped element is: " + stk.pop());
                    break;
            }
        } while(choice != 0);
    }
}
