import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        int n;

        for(int i=0;i<t;i++) {
            n = scanner.nextInt();
            int[] w = new int[n];
            int res=0;

            for(int j=0;j<n;j++) {
                w[j] = scanner.nextInt();
            }
            boolean[][] wasUsed = new boolean[n][2*n+10];

            Map<Integer, Integer> weightTimes = new HashMap<>();

            for(int j=0;j<n-1;j++) { // first weight
                for(int k=j+1;k<n;k++) { //2nd weight
                    if( !wasUsed[j][w[j]+w[k]] && !wasUsed[k][w[j]+w[k]]   ) {
                        int key = w[j] + w[k];
                        if(weightTimes.containsKey(key)) {
                            int times = weightTimes.get(key);
                            times++;
                            res = Math.max(res, times);
                            weightTimes.put(key, times);
                        }
                        else {
                            weightTimes.put(key, 1);
                            res = Math.max(res, 1);
                        }

                        wasUsed[j][key] = true;
                        wasUsed[k][key] = true;




                    }

                }
            }

            System.out.println(res);



        }
    }
}