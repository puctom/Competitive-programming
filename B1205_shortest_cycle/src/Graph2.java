import java.util.ArrayList;
import java.util.LinkedList;

public class Graph2 {

    private int V = 2*60;
    private ArrayList<ArrayList<Integer>> g = new ArrayList<>(V);

    public Graph2() {
        for(int i=0;i<=V;i++)
            g.add(new ArrayList<>());
    }

    public void addEdge(int u, int w) {
        g.get(u).add(w);
        g.get(w).add(u);
    }

    public ArrayList<Integer> getNeighbours(int v) {
        return g.get(v);
    }

    public int doBFS(int start, int goal) {
        LinkedList<Integer> bfsqueue = new LinkedList<>();
        bfsqueue.add(start);
        boolean[] added = new boolean[V+5];
        int[] dist = new int[V+5];

        while(bfsqueue.isEmpty() == false) {
            int curV = bfsqueue.poll();

            for(Integer u: g.get(curV)) {
                if(added[u] == false && !(curV==start && u==goal)) {
                    bfsqueue.add(u);
                    added[u] = true;
                    dist[u] = dist[curV]+1;
                }
            }
        }

        return dist[goal];
    }
}
