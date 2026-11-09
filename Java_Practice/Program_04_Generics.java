public class Program_04_Generics {
    public static <T extends Number> void swap(T n1, T n2) {
        T temp = n1;
        n1 = n2;
        n2 = temp;
    }
    public static void main(String[] args) {
        int n1 = 10;
        int n2 = 20;
        swap(n1, n2);
        System.out.println(n1 + " " + n2);
    }
}
