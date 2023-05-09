import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;
// Working program with FastReader
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

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



    public static void main(String[] args) {
        FastReader scanner = new FastReader();

        int t = scanner.nextInt();
        int n=0,k=0;
        final int MAX_K=4*100*1000;

        for(int i=0;i<t;i++) {
            n = scanner.nextInt();
            k= scanner.nextInt();
            int[] dp = new int[k+3];
            Integer[] x = new Integer[k+3];
            for(int j=0;j<k;j++) {
                x[j]  = scanner.nextInt();
            }


            Arrays.sort(x, 0, k);


        /*    for(int j=0;j<k;j++) {
                System.out.println(x[j]);
            }*/
            dp[k] = 0;
            int res=0;
            for(int j=k-1;j>=0;j--) {
                res=k-j;
                dp[j] = n-x[j] + dp[j+1];
                if(dp[j]>n-1) {
                    res=res-1;
                    break;
                }

            }

          /*  for(int j=0;j<=k;j++) {
                System.out.println("dp["+j+"] = "+dp[j]);
            }*/

            System.out.println(res);



        }


    }
}
