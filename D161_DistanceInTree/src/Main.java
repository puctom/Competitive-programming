import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int k = scanner.nextInt();

        int a,b;
        Graph G = new Graph(n, k);
        for(int i=0;i<n-1;i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            G.addEdge(a,b);

        }

        int[][] dist = G.dodfs(k);
        long res = 0L;
        res = G.calculateResult();
        /*for(int i=1;i<=n;i++) {
            for(int j=0;j<=k;j++) {
                System.out.print("dist["+i+"]["+j+"] = " + dist[i][j]+ " " );
            }
            System.out.println();
        }*/

        System.out.println(res);



    }
}


 class Graph {
    private int V;
    private ArrayList<ArrayList<Integer>> g;
    int[][] dist;
    int k;

    public Graph(int V, int k) {
        this.V = V;
        this.k = k;
        g = new ArrayList<>();
        for(int i=0;i<=V;i++) {
            g.add(new ArrayList<>());
        }
        this.dist = new int [V+2][k+2];
        for(int i=1;i<=V;i++) {
            dist[i][0]=1;
        }
    }

    public void addEdge(int u, int v) {
        g.get(u).add(v);
        g.get(v).add(u);
    }

    public int[][] dodfs(int k) {

        boolean[] visited = new boolean[V+2];
        dfsUtil(1, -1, visited, k, dist);

        return dist;
    }

    public void dfsUtil(int v, int parent, boolean[] visited, int k, int[][] dist) {
        visited[v] = true;
        for(Integer u: g.get(v)) {
            if(visited[u] == false) {
                //dist[v][1]++;
                dfsUtil(u,v, visited, k, dist);

                for(int i=1;i<=k; i++) {
                    dist[v][i]+=dist[u][i-1];
                }
            }


        }

    }

    public long calculateResult() {
        boolean[] visited = new boolean[V+2];
        /*for(int i=1;i<=V;i++) {
            System.out.println(g.get(i));
        }*/
        double res = 0;
        for(int i=1;i<=V;i++) {
            visited[i]=true;
            res+=dist[i][k];
            //System.out.println(dist[i][k] +  " paths ending in " + i);
            //double resTemp = res;
            for(Integer u: g.get(i)) {
                if(visited[u] == false) {
                    for(int j=0;j<=k-2;j++) {
                        // System.out.println((1.0/2.0 * dist[u][j]*(dist[i][k-1-j] - dist[u][k-2-j])) + " paths in the subtree of " + i + " son: " + u);
                        res+=1.0/2.0 * dist[u][j]*(dist[i][k-1-j] - dist[u][k-2-j]);
                    }
                }

            }


        }
        return (long)res;
    }




}
