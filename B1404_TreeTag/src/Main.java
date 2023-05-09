import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //https://codeforces.com/problemset/problem/1404/B
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        for(int i=0;i<t;i++) {
            int n = scanner.nextInt();
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int da = scanner.nextInt();
            int db = scanner.nextInt();

            Graph g = new Graph(n);

            for(int j=0;j<n-1;j++) {
                int x = scanner.nextInt();
                int y = scanner.nextInt();
                g.addEdge(x,y);
            }


            int x = g.bfs(a);
            int dab = g.getDistFromStart()[b];
            int y = g.bfs(x);
            int md = g.getDistFromStart()[y];

            if(dab<=da||!(db>2*da)||md<=2*da) {
                System.out.println("Alice");

            }
            else {
                System.out.println("Bob");
            }

        }
    }
}


 class Graph {

    private int n;

    private ArrayList<ArrayList<Integer>> g = new ArrayList<>();
    private int[] distFromStart;

    public Graph(int n) {
        this.n = n;
        distFromStart = new int[n+2];
        for(int i=0;i<=n;i++) {
            g.add(new ArrayList<>());
        }

    }

    public int[] getDistFromStart() {
        return distFromStart;
    }

    public int bfs(int a) {
        LinkedList<Integer> bfsqueue = new LinkedList<>();
        boolean[] added = new boolean[n+2];
        bfsqueue.add(a);
        added[a] = true;
        distFromStart[a] = 0;
        int x = a;

        while(bfsqueue.isEmpty() == false ) {
            int v = bfsqueue.poll();

            for(Integer u: g.get(v)) {
                if(added[u] == false) {
                    bfsqueue.add(u);
                    added[u] = true;
                    distFromStart[u] = distFromStart[v]+1;
                    if(distFromStart[u]>distFromStart[x])
                        x = u;
                }
            }
        }

        return x;


    }

    public void addEdge(int v, int u) {
        g.get(v).add(u);
        g.get(u).add(v);
    }
}
