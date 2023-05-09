import java.util.Scanner;
import java.util.Stack;
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
        //https://codeforces.com/problemset/problem/547/B
        FastReader scanner = new FastReader();
        int n = scanner.nextInt();
        int[] h = new int[n+2];
        int[] l = new int[n+2]; //index of the closest shorter element to the left
        int[] r = new int[n+2]; //index of the closest shorter element to the right
        int[] ans = new int[n+2];
        for(int i=1;i<=n;i++) {
            h[i] = scanner.nextInt();
        }
        Stack<Integer> stack = new Stack<>();
        for(int i=1;i<=n;i++) {
            while(!stack.empty()&&h[stack.peek()] >= h[i])
                stack.pop();
            if(stack.empty()) {
                l[i] = 0;
            }
            else
                l[i] = stack.peek();
            stack.push(i);
            //System.out.println("l[" + i + "] = " + l[i]);
        }

        stack = new Stack<>();
        for(int i=n;i>=1;i--) {
            while(!stack.empty()&&h[stack.peek()] >= h[i])
                stack.pop();
            if(stack.empty()) {
                r[i] = n+1;
            }
            else
                r[i] = stack.peek();
            stack.push(i);
            //System.out.println("r[" + i + "] = " + r[i]);
        }

        for(int i=1;i<=n;i++) {
            int len = r[i]-l[i]-1;
            ans[len] = Math.max(ans[len], h[i]);
        }
        /*for(int i=1;i<=n;i++)
            System.out.print(ans[i]+" ");*/

        for(int i=n-1;i>=1;i--) {
            ans[i] = Math.max(ans[i],ans[i+1]);

        }
        //System.out.println();
        for(int i=1;i<=n;i++)
            System.out.print(ans[i]+" ");


    }
}