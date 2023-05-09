import java.util.HashMap;
import java.util.Map;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.Map.Entry;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        int n;

        for(int i=0;i<t;i++) {
            n = scanner.nextInt();
            Set<Integer> setUnique = new HashSet<>();
            int[] a = new int[n];
            for(int j=0;j<n;j++) {
                a[j] = scanner.nextInt();
                setUnique.add(a[j]);
            }

            int unique = setUnique.size();
            int mostDuplicates  = occurOfMostFrequent(a);
            //System.out.println("Unique: "+unique + " mostDuplicates: "+mostDuplicates);
            if(unique==mostDuplicates) {
                System.out.println((unique-1));
            }
            else {
                System.out.println(Math.min(unique,mostDuplicates));
            }


        }

    }

    public static int occurOfMostFrequent(int[] tab) {
        Map<Integer, Integer> haszmap = new HashMap<>();

        for(int i=0;i<tab.length;i++) {
            int key = tab[i];

            if(haszmap.containsKey(key)) {
                int freq = haszmap.get(key);
                freq++;
                haszmap.put(key, freq);
            }
            else
                haszmap.put(key, 1);
        }
        int max_count=0;

        for(Entry<Integer, Integer> entry: haszmap.entrySet()) {
            if(max_count<entry.getValue()) {
                max_count = entry.getValue();
            }
        }

        return max_count;
    }
}
