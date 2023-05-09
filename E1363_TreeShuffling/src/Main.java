import java.util.ArrayList;
import java.util.List;
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
        //https://codeforces.com/problemset/problem/1363/e
        FastReader scanner = new FastReader();
        int n = scanner.nextInt();
        Graph g = new Graph(n);
        g.getG().add(null);
        for(int i=0;i<n;i++) {
            int price = scanner.nextInt();
            int original = scanner.nextInt();
            int expected = scanner.nextInt();
            g.getG().add(new Node(i+1, price,original,expected));
        }

        for(int i=0;i<n-1;i++) {
            int a, b;
            a = scanner.nextInt();
            b = scanner.nextInt();
            g.getG().get(a).getAdj().add(g.getG().get(b));
            g.getG().get(b).getAdj().add(g.getG().get(a));
        }

        g.dodfs(g.getG().get(1));
        if(g.getG().get(1).extra0 != g.getG().get(1).extra1) {
            System.out.println("-1");
            return;
        }
        else {
            System.out.println(g.result);
        }



    }
}
class Graph {
    public long result = 0;
    private int n;
    private List<Node> g;

    public Graph(int n) {
        this.n=n;
        this.g = new ArrayList<>();

    }

    public void dodfs(Node v) {
        boolean[] visited = new boolean[n+2];
        dfsUtil(v, null, visited);
    }

    public void dfsUtil(Node v, Node parent, boolean[] visited) {
          //System.out.println("We are visiting node: "+v.getNumber());
        visited[v.getNumber()] = true;
        if(v.getExpected() != v.getOriginal()) {
            if(v.getExpected() == 0)
                v.extra1++;
            else
                v.extra0++;
        }
        for(Node u: g.get(v.getNumber()).getAdj()) {
            //System.out.println("We are trying node nr: "+u.getNumber());
            if(visited[u.getNumber()] == false) {
                u.price = Math.min(u.price, v.price);
                dfsUtil(u, v, visited);
                v.extra0+=u.extra0;
                v.extra1+=u.extra1;

            }

        }
       /*System.out.println("For node: "+v.getNumber()+
                " extra1: "+v.extra1+ "  extra 0: "+v.extra0);*/
        long toExchange = Math.min(v.extra0, v.extra1);
        result += toExchange * (long)v.price * 2l;
        v.extra0 -= toExchange;
        v.extra1 -= toExchange;


    }
    public List<Node> getG() {
        return g;
    }


}


 class Node {
    private int number;
    public int price;
    private int original;
    private int expected;
    public int extra1 = 0;
    public int extra0 = 0;
    private List<Node> adj = new ArrayList<>();

    public Node(int number, int price, int original, int expected) {
        this.number = number;
        this.price = price;
        this.original = original;
        this.expected = expected;
    }

    public int getNumber() {
        return number;
    }

    public int getPrice() {
        return price;
    }

    public int getOriginal() {
        return original;
    }

    public int getExpected() {
        return expected;
    }

    public List<Node> getAdj() {
        return adj;
    }


}
