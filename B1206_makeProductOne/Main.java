import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        int n;
        final int MAX_N= 100_000;
        int[] a = new int[MAX_N];
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        for(int i=0;i<n;i++) {
            a[i] = scanner.nextInt();
        }

        long [][] dp = new long[MAX_N][2]; //row 0 - 1; row 1 - -1
        dp[0][0] = Math.abs(a[0] - 1);
        dp[0][1] = Math.abs(a[0] + 1);

        for(int i=1;i<n;i++) {
            int distToPlus = Math.abs(a[i] - 1);
            int distToMinus = Math.abs(a[i] + 1);
            dp[i][0] = Math.min(distToPlus + dp[i-1][0], distToMinus + dp[i-1][1]);
            dp[i][1] = Math.min(distToPlus + dp[i-1][1], distToMinus + dp[i-1][0]);
        }

        System.out.println(dp[n-1][0]);


    }
}
