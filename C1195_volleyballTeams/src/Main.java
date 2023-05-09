import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //https://codeforces.com/problemset/problem/1195/C
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[][] h = new int[n + 2][2];
        for (int i = 1; i <= n; i++) {
            h[i][0] = scanner.nextInt();

        }
        for (int i = 1; i <= n; i++) {
            h[i][1] = scanner.nextInt();
        }

        long[][] dp = new long[n + 2][3];
        //2 not taking any, 0 - taking 1st row, 1 taking 2nd
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = Math.max(dp[i-1][1], dp[i-1][2]);
            dp[i][0] += h[i][0];

            dp[i][1] = Math.max(dp[i-1][2], dp[i-1][0]);
            dp[i][1] += h[i][1];

            dp[i][2] = Math.max(dp[i-1][0], dp[i-1][1]);

           /* for(int j=0;j<3;j++) {
                System.out.print(dp[i][j]+" ");
            }
            System.out.println();*/
        }
        System.out.println(Math.max(dp[n][0], Math.max(dp[n][1], dp[n][2])));
    }
}