import java.util.ArrayList;
import java.util.PriorityQueue;

public class Graph2 {
    private int n;
    private ArrayList<ArrayList<EdgePair> > g = new ArrayList<>();
    private PriorityQueue<EdgePair> pq = new PriorityQueue<>();
    private long[] bestCost;

    public Graph2(int n) {
        this.n = n;
        this.bestCost = new long[n+2];
        for(int i=0;i<=n;i++)
            bestCost[i] = Integer.MAX_VALUE;
        for(int i=0;i<=n;i++)
            g.add(new ArrayList<>());
    }

    public void addEdgePair(int a, int b, int w, boolean isTrain) {
        this.g.get(a).add(new EdgePair(b, w, isTrain));
        this.g.get(b).add(new EdgePair(a, w, isTrain));
        if(isTrain == true) {
            pq.add(new EdgePair(b, w, true));
        }

    }

    public int doDijkstra() {
        int res = 0;
        boolean[] settled = new boolean[n+3];
        pq.add(new EdgePair(1,0,false));
        bestCost[1] = 0;
        while(!pq.isEmpty()) {
            EdgePair currentEdge = pq.poll();
            int v = currentEdge.getDest();
            boolean isTrain = currentEdge.isTrain();
            long cost = currentEdge.getWeight();
           /* System.out.println("We consider possibilty to get to: "+v+" with the cost: " + cost
            + " train: " + currentEdge.isTrain());*/

            if(isTrain == true && cost >= bestCost[v]) {
                res++;
                //System.out.println("res updated: " + res);
                continue;
            }
            else if (isTrain == true ) {
                bestCost[v] = cost;
            }
            if(settled[v] == true)
                continue;

            settled[v] = true;
           // System.out.println("We take this possibility");
            for(EdgePair edgePairU :g.get(v)) {
                Integer u = edgePairU.getDest();
             //   System.out.println("We coniser neighbour "+ u + " of "+ v);
                if(settled[u] != true && edgePairU.getWeight()+bestCost[v] <= bestCost[u]
                        && edgePairU.isTrain() == false)  {// WARNING DEBUG HERE
                    bestCost[u] = edgePairU.getWeight()+bestCost[v];
                    pq.add(new EdgePair(u,bestCost[u], false ));
                //    System.out.println("We add pair ("+u+ ", "+bestCost[u] + ") to the queue");
                }

            }
        }

    return res;
    }
}
