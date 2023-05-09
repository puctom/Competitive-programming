import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numbers = scanner.nextInt();
        int permutations = scanner.nextInt();
        int[][] position = new int[numbers+3][permutations+3];

        int a;
        for(int i=1;i<=permutations;i++) {
            for(int j=1;j<=numbers;j++) {
                a = scanner.nextInt();
                position[a][i] = j;

            }
        }
        Graph G = new Graph(numbers);
        for(int i=1;i<=numbers;i++) {
            for(int j=1; j<=numbers;j++) {
                boolean isGood = true;
                for(int k = 1;k<=permutations;k++) {
                    if(position[i][k]>=position[j][k])
                        isGood = false;
                }
                if(isGood)
                    G.addEdge(i,j);
            }
        }
        int res;
        //System.out.println(G.toString());
        res = G.dodfs();

        System.out.println(res);


    }
}



 class Graph {
    private int V;
    private ArrayList<ArrayList<Integer>> g;
    private int[] bestLength;
    private int res=0;

    public Graph(int V) {
        this.V = V;
        g = new ArrayList<>();
        for(int i=0;i<=V;i++)
            g.add(new ArrayList<>());

        this.bestLength = new int[V+2];
    }

    public void addEdge(int from, int to) {
        g.get(from).add(to);
    }

    public String toString() {
        String res="";
        for(int i=1;i<=V;i++) {
            res+=g.get(i).toString();
            res+="\n";
        }
        return res;

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
