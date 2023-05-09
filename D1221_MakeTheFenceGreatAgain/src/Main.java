import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    //https://codeforces.com/problemset/problem/1221/D
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                if(st.hasMoreTokens()){
                    str = st.nextToken("\n");
                }
                else{
                    str = br.readLine();
                }
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args)
    {
        FastReader scanner = new FastReader();
        int q = scanner.nextInt();
        for(int t=0;t<q;t++) {
            int n = scanner.nextInt();
            int[] height = new int[n+2];
            height[0] = -10;
            long[] cost = new long[n+2];
            long[][] dp = new long[n+2][3];
            for(int i=1;i<=n;i++) {
                height[i] = scanner.nextInt();
                cost[i] = scanner.nextInt();

                for(int j=0;j<3;j++) {
                    dp[i][j] =Long.MAX_VALUE;
                    for(int k=0;k<3;k++) {
                        if(height[i]+j != height[i-1]+k)
                            dp[i][j]= Math.min(dp[i][j], dp[i-1][k] + j*cost[i]);



                    }
                }
            }
            long res = Long.MAX_VALUE;
            for(int j=0;j<3;j++) {
                res = Math.min(res, dp[n][j]);
            }
            System.out.println(res);




        }
    }
}