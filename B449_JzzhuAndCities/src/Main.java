import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                if (st.hasMoreTokens()) {
                    str = st.nextToken("\n");
                } else {
                    str = br.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) {
        FastReader scanner = new FastReader();
        int numberOfCities, roads, railways;
        numberOfCities = scanner.nextInt();
        roads = scanner.nextInt();
        railways = scanner.nextInt();

        Graph G = new Graph(numberOfCities);

        for (int i = 0; i < roads; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int w = scanner.nextInt();
            G.addEdgePair(a, b, w, false);
        }

        for (int i = 0; i < railways; i++) {
            int b = scanner.nextInt();
            int w = scanner.nextInt();
            G.addEdgePair(1, b, w, true);
        }

        System.out.println(G.doDijkstra());

    }
}

class Graph {
    private int n;
    private ArrayList<ArrayList<EdgePair>> g = new ArrayList<>();
    private PriorityQueue<EdgePair> pq = new PriorityQueue<>();
    private long[] bestCost;

    public Graph(int n) {
        this.n = n;
        this.bestCost = new long[n + 2];
        for (int i = 0; i <= n; i++)
            bestCost[i] = Integer.MAX_VALUE;
        for (int i = 0; i <= n; i++)
            g.add(new ArrayList<>());
    }

    public void addEdgePair(int a, int b, int w, boolean isTrain) {
        this.g.get(a).add(new EdgePair(b, w, isTrain));
        this.g.get(b).add(new EdgePair(a, w, isTrain));
        if (isTrain == true) {
            pq.add(new EdgePair(b, w, true));
        }

    }

    public int doDijkstra() {
        int res = 0;
        boolean[] settled = new boolean[n + 3];
        pq.add(new EdgePair(1, 0, false));
        bestCost[1] = 0;
        while (!pq.isEmpty()) {
            EdgePair currentEdge = pq.poll();
            int v = currentEdge.getDest();
            boolean isTrain = currentEdge.isTrain();
            long cost = currentEdge.getWeight();
           /* System.out.println("We consider possibilty to get to: "+v+" with the cost: " + cost
            + " train: " + currentEdge.isTrain());*/

            if (isTrain == true && cost >= bestCost[v]) {
                res++;
                //System.out.println("res updated: " + res);
                continue;
            } else if (isTrain == true) {
                bestCost[v] = cost;
            }
            if (settled[v] == true)
                continue;

            settled[v] = true;
            // System.out.println("We take this possibility");
            for (EdgePair edgePairU : g.get(v)) {
                Integer u = edgePairU.getDest();
                //   System.out.println("We coniser neighbour "+ u + " of "+ v);
                if (settled[u] != true && edgePairU.getWeight() + bestCost[v] <= bestCost[u]
                        && edgePairU.isTrain() == false) {// WARNING DEBUG HERE
                    bestCost[u] = edgePairU.getWeight() + bestCost[v];
                    pq.add(new EdgePair(u, bestCost[u], false));
                    //    System.out.println("We add pair ("+u+ ", "+bestCost[u] + ") to the queue");
                }

            }
        }

        return res;
    }
}

class EdgePair implements Comparable<EdgePair> {
    private int dest;
    private long weight;
    private boolean isTrain;

    public EdgePair(int dest, long weight, boolean isTrain) {
        this.dest = dest;
        this.weight = weight;
        this.isTrain = isTrain;
    }

    public int getDest() {
        return dest;
    }

    public long getWeight() {
        return weight;
    }

    public boolean isTrain() {
        return isTrain;
    }

    @Override
    public int compareTo(EdgePair that) {
        long costThis = this.getWeight();
        long costThat = that.getWeight();
        if (costThis > costThat)
            return 1;
        if (costThis < costThat)
            return -1;
        if (this.isTrain() == true)
            return -1;
        else
            return 0;
    }
}

