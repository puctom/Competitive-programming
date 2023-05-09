import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        n= scanner.nextInt();
        int[] c = new int[n+2];
        int[][] dp = new int[n+2][n+2];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=0;
        for(int i=0;i<n;i++) {
            c[i] = scanner.nextInt();
        }

        for(int len=0;len<n;len++) {
            for(int begin=0; begin<n;begin++) {
                int end = begin+len;
                if(end>=n)
                    continue;
                if(begin == end) {
                    dp[begin][end] = 1;
                    continue;
                }
                dp[begin][end] = 1+dp[begin+1][end];
                if(c[begin]==c[begin+1])
                    dp[begin][end] = Math.min(dp[begin][end],1+dp[begin+2][end]);

                for(int mid = begin+2;mid<=end;mid++) {
                    if(c[begin]==c[mid]) {
                        dp[begin][end] = Math.min(dp[begin][end], dp[begin+1][mid-1]+dp[mid+1][end]);
                    }
                }




            }
        }

        System.out.println(dp[0][n-1]);
    }
}