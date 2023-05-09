import java.util.Scanner;

public class Mian {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        for(int i=0;i<t;i++) {
            int n = scanner.nextInt();
            int[] a = new int[n];
            int[] dp = new int[n];
            for(int j=0;j<n;j++)
                a[j] = scanner.nextInt();
            int res=-1;
            for(int j=n-1;j>=0;j--) {
                dp[j] = a[j];
                if(j + a[j] < n) {
                    dp[j] += dp[j+a[j]];
                }
                res = Math.max(res, dp[j]);

            }

            System.out.println(res);

        }


    }
}
