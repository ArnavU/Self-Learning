package expressionConversion;

import java.util.Stack;

public class InfixToPostfix {
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

    public static String infixToPostfix(String infix) {
        Stack<Character> stk = new Stack<>(); 
        StringBuffer postfix = new StringBuffer();

        for(int i=0; i<infix.length(); i++) {
            char element = infix.charAt(i);
            if(Character.isDigit(element)) {
                postfix.append(element);
            } else if(element == '(') {
                stk.push(element);
            } else if(element == ')') {
                while(stk.peek() != '(') {
                    postfix.append(stk.pop());
                }
                stk.pop();
            } else {
                while(!stk.empty() && getPriority(stk.peek())>=getPriority(element)) {
                    postfix.append(stk.pop());
                }
                stk.push(element);
            }
        }

        while(!stk.empty()) {
            postfix.append(stk.pop());
        }

        return postfix.toString();
    }

    public static void main(String[] args) {
        String infix = "1$9+3*4-(6+8/2)+7";
		System.out.println("Infix : " + infix);
		
		String postfix =  infixToPostfix(infix);
		System.out.println("Postfix : " + postfix);
    }
}
