import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //https://codeforces.com/problemset/problem/1187/E?locale=en
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Graph g = new Graph(n);

        for(int i=0;i<n-1;i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            g.addEdge(a,b);

        }
        g.dodfsStep(0);
        g.dodfsStep(1);

        System.out.println(Math.max(g.getSubtreeScore()[1],g.getSubtreeDownRes()[1]));
        /*for(int i=1;i<=n;i++) {
            System.out.println("Subtree["+i+"] size: "+g.getSubtreeSize()[i]);
            System.out.println("Subtree["+i+"] down res: "+g.getSubtreeDownRes()[i]);
            System.out.println("Subtree["+i+"] bonus nodes: "+g.getBonusNodes()[i]);
            System.out.println("Subtree["+i+"] score: "+g.getSubtreeScore()[i]);
        }*/
    }
}



 class Graph {
    private int n;
    private ArrayList<ArrayList<Integer>> g = new ArrayList<>();
    private long[] subtreeSize;
     private long[] subtreeBest;
    private long[] subtreeScore;
    private long[] bonusNodes;
    private long[] subtreeDownRes;

    public Graph(int n) {
        this.n = n;
        for(int i=0;i<=n;i++)
            g.add(new ArrayList<>());
        subtreeSize = new long[n+4];
        bonusNodes = new long[n+4];
        subtreeDownRes = new long[n+4];
        subtreeScore = new long[n+4];
        subtreeBest = new long[n+4];
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

    public long[] getSubtreeSize() {
        return subtreeSize;
    }

    public long[] getBonusNodes() {
        return bonusNodes;
    }

    public long[] getSubtreeDownRes() {
        return subtreeDownRes;
    }

    public long[] getSubtreeScore() {
        return subtreeScore;
    }

    public void dfsFinal(int v, int parent, boolean[] visited) {
        visited[v] = true;

        for(Integer u: g.get(v)) {
            if(visited[u]==false) {
                dfsFinal(u,v,visited);
                /*System.out.println("We now consider subtree of: "+v+" with son: "+u);
                System.out.println("subtreeScore["+v+"] = "+subtreeScore[v]+" until now");
                System.out.println("Candidate: son's "+u+" score: "+subtreeScore[u]+ " + "+(bonusNodes[u]+1)
                                +" * "+ (n-subtreeSize[u])+" + "+
                        (subtreeDownRes[v]-subtreeSize[v]-subtreeDownRes[u])  + " (other trees)");
                System.out.println("So we compare: "+(subtreeScore[u]+(bonusNodes[u]+1)*
                        (n-subtreeSize[u])+(subtreeDownRes[v]-subtreeSize[v]-subtreeDownRes[u])) + " to: "+
                        (subtreeBest[v] + (n-subtreeSize[v])*(bonusNodes[v])));*/

                if( subtreeScore[u]+(bonusNodes[u]+1)*
                        (n-subtreeSize[u])+(subtreeDownRes[v]-subtreeSize[v]-subtreeDownRes[u])
                > subtreeBest[v] ) {
                    subtreeBest[v] =  subtreeScore[u]+(bonusNodes[u]+1)*
                            (n-subtreeSize[u])+(subtreeDownRes[v]-subtreeSize[v]-subtreeDownRes[u]);
                    bonusNodes[v] = bonusNodes[u]+1;
                    subtreeScore[v] = subtreeScore[u]+(bonusNodes[u]+1)*
                            (subtreeSize[v]-subtreeSize[u])+(subtreeDownRes[v]-subtreeSize[v]-subtreeDownRes[u]);

                    /*System.out.print("We chose to start from son: "+u+", new bonus for "+v+ " is: "+bonusNodes[v]);
                    System.out.println(" and new best["+v+"] = "+subtreeBest[v]);*/
                }

               /* subtreeScore[v]=Math.max(subtreeScore[v], subtreeScore[u]+(bonusNodes[u]+1)*
                        (subtreeSize[v]-subtreeSize[u])+(subtreeDownRes[v]-subtreeSize[v]-subtreeDownRes[u]));*/

                //System.out.println("new result for subtreeScore["+v+"] = "+subtreeScore[v]);
            }
        }
        subtreeScore[v]=Math.max(subtreeScore[v],1);
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

    }
}
