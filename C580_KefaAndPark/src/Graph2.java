import java.util.ArrayList;

public class Graph2 {

private int V;
private int[] curOngoing;
private int[] curMax;
private ArrayList<Integer> g[];
private boolean[] isCat ;

public Graph2(int v) {
        this.V=v;
        this.g = new ArrayList[v+2];
        for(int i=0;i<g.length;i++)
        g[i] = new ArrayList<>();
        this.curMax = new int[v+2];
        this.curOngoing = new int[v+2];
        this.isCat = new boolean[v+2];
        }
public void setCat(int v, int temp) {
        isCat[v+1] = temp == 1 ? true : false;
        }
public void addEdge(int u, int w) {
        g[u].add(w);
        g[w].add(u);
        }

public int getNumberOfNeigh(int v) {
        return g[v].size();
        }

public int getMax(int v) {
        return curMax[v];
        }

public void DFS(int v) {
        //v - 1st vertex, traversal will start there
        boolean visited[] = new boolean[this.V+3];

        DFSRec(v, -1, visited);
        }

public void DFSRec(int v, int parent, boolean[] visited) {
        if(parent == -1) {
        curOngoing[v] = (isCat[v] == false ? 0 : 1);
        curMax[v] = curOngoing[v];
        }
        else {
        if(isCat[v] == false)
        curOngoing[v] = 0;
        else
        curOngoing[v] = curOngoing[parent]+1;
        curMax[v] = Math.max(curOngoing[v], curMax[parent]);
        }

        visited[v]=true;
        //System.out.println("Visiting vertex: "+v);
        for(Integer w: g[v]) {
        if(!visited[w])
        DFSRec(w, v, visited);

        }



        }



        }
