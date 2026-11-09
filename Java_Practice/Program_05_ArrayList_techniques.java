import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Program_05_ArrayList_techniques {
    public static void main(String[] args) {
        // 1) use methods like add, set, remove
        List<Integer> list1 = new ArrayList<>();
        list1.add(10);
        list1.add(20);
        list1.set(1, 21);
        System.out.println("list1: " + list1);

        // 2) list.of => immutable list
        List<Integer> list2 = List.of(1, 2, 3, 4, 5);
        // list2.add(6); // UnsupportedOperationException
        // list2.set(2, 4); // UnsupportedOperationException
        System.out.println("list2: " + list2);

        // 3) converting primitive array to mutable list
        int[] primitiveArray = {11, 22, 33, 44, 55};
        List<Integer> list3 = Arrays.stream(primitiveArray)
                                    .boxed()
                                    .toList();
        System.out.println("list3: " + list3);

        // 4) Arrays.asList() -> set(update) allowed | add not allowed
        // Warning: use array of only Wrapper class not primitive type in this case
        Integer[] arr1 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        List<Integer> list4 = Arrays.asList(arr1);
        // list4.add(0); // UnsupportedOperationException
        list4.set(9, 0); // allowed
        System.out.println("list4: " + list4);

        // 5) Arrays.asList() -> variation to create mutable list
        String[] arr2 = {"Arnav", "Ram", "Vivek"};
        List<String> list5 = new ArrayList<>(Arrays.asList(arr2));
        list5.add("Vidhur");
        list5.set(2, "Viraj");
        System.out.println("list5: " + list5);

        // 6) Collections.addAll() -> mutable arraylist
        List<String> colors = new ArrayList<>();
        String[] extraColors = {"Purple", "Voilet", "Pink"};
        Collections.addAll(colors, "Red", "White", "Green");
        Collections.addAll(colors, extraColors);
        System.out.println("colors: " + colors);
    }
}
