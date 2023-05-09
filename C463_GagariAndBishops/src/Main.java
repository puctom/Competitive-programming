import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    //https://codeforces.com/problemset/problem/463/C
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
        int n = scanner.nextInt();

        long[][] chessboard = new long[n+2][n+2];
        long[][] squareScore = new long[n+2][n+2];
        long evenBest=0, oddBest=0;
        int evenRow=0, evenCol=0;
        int oddRow=0, oddCol=0;
        long[] rightDiag = new long[2*n+1];
        long[] leftDiag = new long[2*n+1];

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                chessboard[i][j] = scanner.nextInt();
        for(int i=1;i<2*n;i++) {
            for(int j=i;j>=1;j--) {
                //System.out.println("Diag no. "+i+" j ="+j);
                //System.out.println("We add cell: "+(Math.min(i,n)-j+1)+", "+j);
                if(i-j+1>n || j>n)
                    continue;
                rightDiag[i]+=chessboard[i-j+1][j];
            }
           // System.out.println("Right diag["+i+"] = "+rightDiag[i]);
        }

        for(int i=1;i<2*n;i++) {
            for(int j=1;j<=n;j++) {
                //System.out.println("Diag no. "+i+" j ="+j);
                //System.out.println("We add cell: "+(Math.min(i,n)-j+1)+", "+j);
                if(n-i+j>n || j>n || n-i+j<0 )
                    continue;
                leftDiag[i]+=chessboard[n-i+j][j];
            }
           // System.out.println("leftDiag["+i+"] = "+leftDiag[i]);
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                squareScore[i][j] = rightDiag[i+j-1] + leftDiag[n+j-i]-chessboard[i][j];
                if((i+j)%2 == 0) {
                    if(squareScore[i][j]>=evenBest) {
                        evenBest = squareScore[i][j];
                        evenRow = i;
                        evenCol = j;
                    }


                }
                else {
                    if(squareScore[i][j]>=oddBest) {
                        oddBest = squareScore[i][j];
                        oddRow = i;
                        oddCol = j;
                    }
                }

            }
        }
        System.out.println((evenBest+oddBest));
        System.out.println(evenRow+" "+evenCol+" "+oddRow+" "+oddCol);

    }
}