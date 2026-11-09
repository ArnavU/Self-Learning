
class Singleton {
    private static Singleton obj;
    static {
        obj = new Singleton();
    }

    private Singleton() { }

    static Singleton getInstance() {
        return obj;
    }
}

public class Program_03_Singleton {
    public static void main(String[] args) {
        Singleton obj1 = Singleton.getInstance();
        Singleton obj2 = Singleton.getInstance();

        System.out.println(obj1==obj2);
    }    
}
