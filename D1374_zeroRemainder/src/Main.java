import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        int n,k;

        for(int i=0;i<t;i++) {

            n= scanner.nextInt();
            k= scanner.nextInt();
            int[] a = new int[n];
            Map<Integer, Integer> reminderTimes = new HashMap<>();
            int max_count=0, lowest_rem=0;

            for(int j=0;j<n;j++) {
                a[j] = scanner.nextInt();
                a[j] = a[j] %k;
                if(a[j] == 0)
                    continue;
                if(reminderTimes.containsKey(a[j])) {
                    int times = reminderTimes.get(a[j]);
                    times++;
                    reminderTimes.put(a[j], times);
                    if(times>max_count) {
                        max_count = times;
                        lowest_rem = a[j]%k;
                       // System.out.println("j = " + j + " lowest reaminder set to: "+a[j]%k);
                    }
                    if(times==max_count) {
                        if(lowest_rem>a[j]%k && a[j] > 0) {
                            lowest_rem = a[j]%k;
                          //  System.out.println("inner j = " + j + "lowest reaminder set to: "+a[j]%k);
                        }
                    }
                    //System.out.println("a["+j+"] = "+a[j] + "inserted, max_count: " + max_count);
                }
                else {
                   reminderTimes.put(a[j],1);
                   if(1>max_count) {
                       max_count = 1;
                       lowest_rem = a[j]%k;

                   }
                   if(1==max_count) {
                       if(lowest_rem>a[j]%k) {
                           lowest_rem = a[j]%k;
                       }
                   }
                }



            }
            //System.out.println("Most times: "+lowest_rem+" count: "+max_count);
            long res=0;

            res = ((long)max_count-1L) * (long)k + ((long)k-(long)lowest_rem+1L);
            if(lowest_rem == 0)
                res=0;
            System.out.println(res);

        }

    }
}