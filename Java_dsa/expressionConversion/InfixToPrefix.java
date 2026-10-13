package expressionConversion;

import java.util.Stack;

public class InfixToPrefix {

    public static int getPriority(char op) {
        switch(op) {
            case '$': return 10;
            case '*': return 9;
            case '/': return 9;
            case '%': return 9;
            case '+': return 8;
            case '-': return 8;
        }
        return 0;
    }

    public static String infixToPrefix(String infix) {
        Stack<Character> stk = new Stack<>();
        StringBuffer prefix = new StringBuffer();

        for(int i=infix.length()-1; i>=0; i--) {
            char element = infix.charAt(i);
            if(Character.isDigit(element)) {
                prefix.append(element);
            } else if(element == ')') {
                stk.push(element);
            } else if(element == '(') {
                while(stk.peek()!=')') {
                    prefix.append(stk.pop());
                }
                stk.pop();
            } else {
                while(!stk.empty() && getPriority(stk.peek()) > getPriority(element)) {
                    prefix.append(stk.pop());
                }
                stk.push(element);
            }
        }
        while(!stk.empty()) {
            prefix.append(stk.pop());
        }
        prefix.reverse();
        return prefix.toString();
    }

    public static void main(String[] args) {
        String infix = "1$9+3*4-(6+8/2)+7";
		System.out.println("Infix : " + infix);
		
		String prefix = infixToPrefix(infix);
		System.out.println("Prefix : " + prefix);
    }   
}
