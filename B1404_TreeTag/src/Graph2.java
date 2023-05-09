import java.util.ArrayList;
import java.util.LinkedList;

public class Graph2 {

    private int n;

    private ArrayList<ArrayList<Integer>> g = new ArrayList<>();
    private int[] distFromStart;

    public Graph2(int n) {
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
