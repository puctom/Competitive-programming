import java.util.ArrayList;
import java.util.Scanner;
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
        //https://codeforces.com/problemset/problem/1324/F
       // Scanner scanner = new Scanner(System.in);
        FastReader scanner = new FastReader();
        int n = scanner.nextInt();

        Graph g = new Graph(n);
        for(int i=1;i<=n;i++) {
            int color = scanner.nextInt();
            if(color==0)
                color=-1;
            g.setColor(i, color);
        }

        for(int i=0;i<n-1;i++) {
            int a=scanner.nextInt();
            int b=scanner.nextInt();
            g.addEdge(a,b);
        }
        g.dodfs(0);
        g.dodfs(1);

        for(int i=1;i<=n;i++)
            System.out.print(g.getRes()[i] + " ");
    }
}



 class Graph {
    private int n;
    private int[] res;
    private int[] color ;
    private ArrayList<ArrayList<Integer>> g = new ArrayList<>();

    public Graph(int n) {
        this.n=n;
        color = new int[n+3];
        res = new int[n+3];
        for(int i=0;i<=n;i++) {
            g.add(new ArrayList<>());
            res[i]=Integer.MIN_VALUE;
        }





    }

    public void dodfs(int step) {
        boolean[] visited = new boolean[n+3];
        if(step == 0) {
            this.dfsInitial(1,-1,visited);
        }
        else {
            this.dfsFinal(1,-1,visited);
        }
    }

    public void dfsInitial(int v, int parent, boolean[] visited) {
        visited[v] = true;

        res[v]=Math.max(res[v], color[v]);
        for(Integer u: g.get(v)) {
            if(visited[u] == false) {
                dfsInitial(u,v,visited);
                res[v] = Math.max(res[v], res[v]+res[u]);
            }
        }

        //System.out.println("After initial: res["+v+"] = "+ res[v]);
    }

    public void dfsFinal(int v, int parent, boolean[] visited) {
        visited[v] = true;
        for(Integer u: g.get(v)) {
            if(visited[u] == false) {
                if(res[u]<=0) {
                    res[u]=Math.max(res[u], res[u]+res[v]);
                }
                else {
                    res[u]=Math.max(res[u], res[v]);
                }
                dfsFinal(u,v,visited);
            }
        }
    }

    public void setColor(int idx, int color) {
        this.color[idx] = color;
    }

    public int[] getRes() {
        return res;
    }

    public void addEdge(int u, int v) {
        g.get(u).add(v);
        g.get(v).add(u);
    }


}
