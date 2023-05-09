import java.util.LinkedList;
import java.util.List;

public class Graph2 {

    private boolean[][] reachable;
    private char[][] cave;
    private int height;
    private int width;
    private Point finish;

    private final static int[] rowDir = {0, 1, 0, -1};
    private final static int[] colDir = {1, 0, -1, 0};

    public Graph2(char[][] cave, Point finish) {
        this.cave = cave;
        this.height = cave.length-3;
        this.width = cave[0].length-3;
        reachable = new boolean[height+3][width+3];
        this.finish = finish;
    }
    public boolean canBeReached(Point p) {
        return p.getRow()<=height && p.getRow()>0 &&
                p.getCol()<=width && p.getCol()>0;

    }


    public int countSolid(Point p) {
        int res=0;
        for(int i=0;i<4;i++) {
            Point u = new Point(p.getRow()+rowDir[i], p.getCol()+colDir[i]);
            if(canBeReached(u))
                res+= (cave[u.getRow()][u.getCol()]=='.' ? 1: 0);
        }
        return res;
    }
    public void bfs(Point start) {
        LinkedList<Point> bfsQueue = new LinkedList<>();
        boolean[][] added = new boolean[height+2][width+2];

        bfsQueue.add(start);
        added[start.getRow()][start.getCol()] = true;
        reachable[start.getRow()][start.getCol()] = true;
        while(bfsQueue.isEmpty() == false) {
            Point v = bfsQueue.poll();

            for(int i=0;i<4;i++) {

                    Point u = new Point(v.getRow()+rowDir[i], v.getCol()+colDir[i]);
                    if(canBeReached(u) && added[u.getRow()][ u.getCol() ] == false &&
                        (cave[u.getRow()][u.getCol()] != 'X' || u.equals(finish))) {
                        reachable[u.getRow()][  u.getCol() ] = true;
                        added[u.getRow()][  u.getCol() ] = true;
                        bfsQueue.add(u);

                }
            }

        }

    }

    public boolean[][] getReachable() {
        return reachable;
    }
}
