import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        FastReader  scanner = new FastReader ();

        int nExp = scanner.nextInt();
        int[] tree = new int[1<<(nExp+1)];
        int q = scanner.nextInt();
        for(int i=0;i< (1<<nExp);i++)
            tree[(1<<nExp) + i] = scanner.nextInt();

        int xorORor = 1;
        int currExp = nExp-1;
        for(int i=(1<<nExp)-1;i>=1;i--) {
            if(xorORor == 0)
                tree[i] = (tree[2*i] ^ tree[2*i+1]);
            else
                tree[i] = (tree[2*i] | tree[2*i+1]);



            if(i==(1<<currExp)) {
                currExp--;
                xorORor = 1-xorORor;
            }




        }

        /*for(int k=nExp;k>=0;k--) {
            for(int l=0;l<(1<<k);l++)
                System.out.print(tree[l+(1<<k)] + " ");
            System.out.println();
        }*/



        for(int i=0;i<q;i++) {
            int idx = scanner.nextInt();
            idx+=(1<<nExp)-1;
            int newVal = scanner.nextInt();
            tree[idx] = newVal;

            /*for(int k=nExp;k>=0;k--) {
                for(int l=0;l<(1<<k);l++)
                    System.out.print(tree[l+(1<<k)] + " ");
                System.out.println();
            }*/

            for(int j=1;j<=nExp;j++) {
                idx/=2;
                if(j%2 == 1) { //or
                    tree[idx] = tree[2*idx] | tree[2*idx+1];

                }
                else { //xor

                    tree[idx] = tree[2*idx] ^ tree[2*idx+1];


                }


                /*for(int k=nExp;k>=0;k--) {
                    for(int l=0;l<(1<<k);l++)
                        System.out.print(tree[l+(1<<k)] + " ");
                    System.out.println();
                }*/
            }

            System.out.println(tree[1]);
        }
    }

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
}