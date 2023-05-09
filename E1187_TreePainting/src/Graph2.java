import java.util.ArrayList;

public class Graph2 {
    private int n;
    private ArrayList<ArrayList<Integer>> g = new ArrayList<>();
    private int[] subtreeSize;
    private int[] subtreeScore;
    private int[] bonusNodes;
    private int[] subtreeDownRes;

    public Graph2(int n) {
        this.n = n;
        for(int i=0;i<=n;i++)
            g.add(new ArrayList<>());
        subtreeSize = new int[n+4];
        bonusNodes = new int[n+4];
        subtreeDownRes = new int[n+4];
        subtreeScore = new int[n+4];
    }

    public void addEdge(int u, int v) {
        g.get(u).add(v);
        g.get(v).add(u);
    }

    public void dodfsStep(int step) {
        boolean[] visited = new boolean[n+4];
        if(step ==0)
            dfsUtilinitial(1,-1, visited);
        else
            dfsFinal(1,-1,visited);
    }

    public int[] getSubtreeSize() {
        return subtreeSize;
    }

    public int[] getBonusNodes() {
        return bonusNodes;
    }

    public int[] getSubtreeDownRes() {
        return subtreeDownRes;
    }

    public int[] getSubtreeScore() {
        return subtreeScore;
    }

    public void dfsFinal(int v, int parent, boolean[] visited) {
        visited[v] = true;

        for(Integer u: g.get(v)) {
            if(visited[u]==false) {
                dfsFinal(u,v,visited);
                //System.out.println("We now consider subtree of: "+v+" with son: "+u);

                subtreeScore[v]=Math.max(subtreeScore[v], subtreeScore[u]+(bonusNodes[u]+1)*
                        (subtreeSize[v]-subtreeSize[u])+(subtreeDownRes[v]-subtreeSize[v]-subtreeDownRes[u]));

            }
        }
    }

    public void dfsUtilinitial(int v, int parent, boolean[] visited) {
        //System.out.println("In vertex: "+v);
        visited[v] = true;
        for(Integer u: g.get(v)) {
            if(visited[u] == false ) {
                dfsUtilinitial(u,v,visited);
                subtreeSize[v] += subtreeSize[u];
                subtreeDownRes[v]+=subtreeDownRes[u];
                bonusNodes[v]=Math.max(bonusNodes[v], bonusNodes[u]);
            }


        }
        bonusNodes[v]+=1;
        subtreeSize[v]+=1;
        subtreeDownRes[v]+=subtreeSize[v];
        subtreeScore[v]=1;
    }
}
