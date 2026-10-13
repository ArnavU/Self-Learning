package expressionEvaluation;

public class PrefixEvaluation {
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
	    String prefix = "-++4/*56397";
        int[] stk = new int[10];
        int top = -1;

        for(int i=prefix.length()-1; i>=0; i--) {
            char element = prefix.charAt(i);

            // if operand the convert and push to stack
            if(Character.isDigit(element)) {
                stk[++top] = element - '0';
            } else {
                int op1 = stk[top--];
                int op2 = stk[top--];
                int res = calculate(op1, element, op2);
                stk[++top] = res;
            }
        }
        
        System.out.println(String.format("%s : %d", prefix, stk[top]));
    }
}
