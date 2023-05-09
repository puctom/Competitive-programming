import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        String s = scanner.nextLine();
        Map<String, Integer> hashmap = new HashMap<>();
        for(int i=0;i<n;i++) {
            s = scanner.nextLine();
            //System.out.println("\n\nScanned word was: "+s);

            if(hashmap.containsKey(s)) {
                int times = hashmap.get(s);
                System.out.println(s+times);
                times++;
                hashmap.put(s,times);
            }
            else {
                System.out.println("OK");
                hashmap.put(s,1);
            }



        }
    }
}