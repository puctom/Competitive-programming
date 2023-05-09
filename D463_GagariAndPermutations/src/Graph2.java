import java.util.ArrayList;

public class Graph2 {
    private int V;
    private ArrayList<ArrayList<Integer>> g;
    private int[] bestLength;
    private int res=0;

    public Graph2(int V) {
        this.V = V;
        g = new ArrayList<>();
        for(int i=0;i<=V;i++)
            g.add(new ArrayList<>());

        this.bestLength = new int[V+2];
    }

    public void addEdge(int from, int to) {
        g.get(from).add(to);
    }

    public int dodfs() {
        boolean[] visited = new boolean[V+2];

        for(int i=1;i<=V;i++) {
            if(visited[i] == false) {
                dfsUtil(i, visited);
            }
        }

        return res;

    }

    public void dfsUtil(int v, boolean[] visited) {

        visited[v] = true;

        for(Integer u: g.get(v)) {
            if(visited[u] == false)
                dfsUtil(u, visited);
            bestLength[v] = Math.max(bestLength[v], bestLength[u]+1);
        }
        bestLength[v] = Math.max(bestLength[v], 1);

        res= Math.max(res, bestLength[v]);

    }
}
