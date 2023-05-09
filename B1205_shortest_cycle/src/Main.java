import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        ArrayList<ArrayList<Integer>> bitOn =  new ArrayList<>();
        for(int i=0;i<60;i++)
            bitOn.add(new ArrayList<Integer>());
        long[] a = new long[n+3];
        for(int i=1;i<=n;i++) {
            a[i] = scanner.nextLong();
            if(a[i] == 0) {
                i--;
                n--;
                continue;
            }
            for(long j=0;j<60;j++) {
                if((a[i] & (1L<<j)) > 0) {
                    bitOn.get((int)j).add(i);
                }
            }
        }

        /*for(int i=0;i<60;i++) {
            System.out.println(i+ ": "+ bitOn.get(i));
        }*/


        for(int i=0;i<60;i++) {
            if(bitOn.get(i).size() >= 3) {
                System.out.println(3);
                return;
            }

        }

        Graph G = new Graph();
        for(int i=0;i<60;i++) {
            if(bitOn.get(i).size()==2)
                G.addEdge(bitOn.get(i).get(0), bitOn.get(i).get(1));
        }
        int curAns=Integer.MAX_VALUE-2;
        int res = Integer.MAX_VALUE-2;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
              //  System.out.println("We consider pair: " + i + " "+  j);
                if(G.getNeighbours(i).contains(j)) {
                  //  System.out.println("There is an edge");
                    curAns = G.doBFS(i,j);
                  //  System.out.println("Distance was: " + curAns);
                    if(curAns<2)
                        curAns=Integer.MAX_VALUE-2;
                }
                res = Math.min(res, curAns+1);
            //   System.out.println("now, res = " + res + "\n");

            }
        }
        if(res>Integer.MAX_VALUE-4)
            res=-1;
        System.out.println(res);


    }
}

 class Graph {

    private int V = 2*62;
    private ArrayList<ArrayList<Integer>> g = new ArrayList<>(V);

    public Graph() {
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
