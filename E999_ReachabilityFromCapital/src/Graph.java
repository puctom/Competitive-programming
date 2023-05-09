import java.util.ArrayList;
/*
public class Graph {
    private int n;
    private ArrayList<ArrayList<Integer>> g = new ArrayList<>();
    private ArrayList<ArrayList<Integer>> gt = new ArrayList<>();
    private int[] scc;
    private int[] sccIndeg;
    private boolean[] reachableSCC;
    private ArrayList<Integer> postorder = new ArrayList<>();

    public Graph(int n) {
        this.n=n;
        for(int i=0;i<=n;i++) {
            g.add(new ArrayList<>());
            gt.add(new ArrayList<>());

        }
        this.scc = new int[n+3];
    }

    public void addEdge(int a, int b) {
        g.get(a).add(b);
        gt.get(b).add(a);
    }

    public void doDFS(int step) {
        boolean[] visited = new boolean[n+3];

        switch (step) {
            case 1:
                for(int i=1;i<=n;i++)
                    if(visited[i] == false)
                        this.doDFSInitial(i, visited);
                break;
            case 2:
                int count = 0;
                for(int i=postorder.size()-1;i>=0;i--) {
                    if(visited[postorder.get(i)] == false) {
                        this.doDFStransposed(postorder.get(i), visited, count);
                        count++;
                    }

                }
                Main.SCCGraph = new Graph(this.getScc()[this.getPostorder().get(0)]);
                Main.SCCGraph.sccIndeg = new int[count+2];
                Main.SCCGraph.reachableSCC = new boolean[count+2];
                break;
            case 3:
                for(int i=1;i<=n;i++)
                    if(visited[i] == false)
                        doDfsSccGraph(i, visited);

                break;
            case 4:
                doDFSCapital(Main.G.getScc()[Main.getCapitalIndex()], reachableSCC);
        }

    }

    public void doDFSCapital(int v, boolean[] reachableSCC) {
        reachableSCC[v] = true;
        for(Integer u: this.g.get(v)) {
            if(reachableSCC[u] == false) {
                doDFSCapital(u, reachableSCC);
            }
        }

    }

    public  void doDfsSccGraph(int v, boolean[] visited) {
        visited[v] = true;
       // System.out.println("We start considering " +v);
        for(Integer u: g.get(v)) {
         //   System.out.println("We consider neighbour: "+u+" of "+v);
            if(visited[u]==false && scc[v] != scc[u]) {
                Main.SCCGraph.addEdge(scc[v], scc[u]);
                Main.SCCGraph.sccIndeg[scc[u]]++;

            }
        }
    }

    public void doDFStransposed(int v, boolean[] visited, int count) {
      //  System.out.println("We start considering " +v+", current count: "+count);
        visited[v] = true;
        scc[v] = count;
        for(Integer u: gt.get(v)) {
         //   System.out.println("We consider neighbour: "+u+" of "+v);
            if(visited[u] == false)
                doDFStransposed(u, visited, count);
        }
      //  System.out.println("We finished considering " +v);

    }

    public void doDFSInitial(int v, boolean[] visited) {
        visited[v] = true;
        for(Integer u: this.g.get(v)) {
            if(visited[u] == false)
                doDFSInitial(u, visited);
        }
        postorder.add(v);
    }

    public int[] getSccIndeg() {
        return sccIndeg;
    }

    public boolean[] getReachableSCC() {
        return reachableSCC;
    }

    public int[] getScc() {
        return scc;
    }

    public int getN() {
        return n;
    }

    public ArrayList<ArrayList<Integer>> getG() {
        return g;
    }

    public ArrayList<ArrayList<Integer>> getGt() {
        return gt;
    }

    public ArrayList<Integer> getPostorder() {
        return postorder;
    }
}

 */

