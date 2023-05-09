import java.util.Collections;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        final int MAX_N = 100;
        int n;
        int totalSum=0;
        Integer[] coins = new Integer[MAX_N];

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        for(int i=0;i<n;i++) {
            coins[i] = scanner.nextInt();
            totalSum+=coins[i];
        }

        Arrays.sort(coins, 0, n, Collections.reverseOrder());
        //5
        // System.out.println(Arrays.toString(coins));
        //System.out.println(totalSum);
        int tempSum=0;

        int res=0;
        for(int i=0;i<n;i++) {
            tempSum+=coins[i];
            if(tempSum>totalSum/2) {
                res=i+1;
                break;
            }
        }

        System.out.println(res);



    }
}
