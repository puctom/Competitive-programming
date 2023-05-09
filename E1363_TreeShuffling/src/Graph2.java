import java.util.ArrayList;
import java.util.List;

public class Graph2 {
    public int result = 0;
    private int n;
    private List<Node> g;

    public Graph2(int n) {
        this.n=n;
        this.g = new ArrayList<>();

    }

    public void dodfs(Node v) {
        boolean[] visited = new boolean[n+2];
        dfsUtil(v, null, visited);
    }

    public void dfsUtil(Node v, Node parent, boolean[] visited) {
      //  System.out.println("We are visiting node: "+v.getNumber());
        visited[v.getNumber()] = true;
        if(v.getExpected() != v.getOriginal()) {
            if(v.getExpected() == 0)
                v.extra1++;
            else
                v.extra0++;
        }
        for(Node u: g.get(v.getNumber()).getAdj()) {
            if(visited[u.getNumber()] == false) {
                u.price = Math.min(u.price, v.price);
                dfsUtil(u, v, visited);
                v.extra0+=u.extra0;
                v.extra1+=u.extra1;

            }

        }
       /* System.out.println("For node: "+v.getNumber()+
                " extra1: "+v.extra1+ "  extra 0: "+v.extra0);*/
        int toExchange = Math.min(v.extra0, v.extra1);
        result += toExchange * v.price * 2;
        v.extra0 -= toExchange;
        v.extra1 -= toExchange;


    }
    public List<Node> getG() {
        return g;
    }


}
