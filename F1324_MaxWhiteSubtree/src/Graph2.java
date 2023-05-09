import java.util.ArrayList;

public class Graph2 {
    private int n;
    private int[] res;
    private int[] color ;
    private ArrayList<ArrayList<Integer>> g = new ArrayList<>();

    public Graph2(int n) {
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
