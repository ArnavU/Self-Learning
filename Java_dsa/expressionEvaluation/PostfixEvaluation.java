package expressionEvaluation;

public class PostfixEvaluation {
    public static int calculate(int op1, char operator, int op2) {
        switch(operator) {
            case '*': return op1*op2;
            case '/': return op1/op2;
            case '-': return op1-op2;
            case '+': return op1+op2;
            case '%': return op1%op2;
            case '$': return (int)Math.pow(op1, op2);
        }
        return 0;
    }
    public static void main(String[] args) {
        String postfix = "456*3/+9+7-";
        int[] stk = new int[10];
        int top = -1;

        for(int i=0; i<postfix.length(); i++) {
            char element = postfix.charAt(i);
            if(Character.isDigit(element)) {
                int ele = element-'0';
                stk[++top] = ele;        
            } else {
                int op2 = stk[top--];
                int op1 = stk[top--];
                int res = calculate(op1, element, op2);
                stk[++top] = res;
            }
        }
        
        System.out.println(String.format("%s : %d", postfix, stk[top]));
    }
}
