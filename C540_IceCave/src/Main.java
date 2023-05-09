import java.util.LinkedList;
import java.util.Objects;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int height = scanner.nextInt();
        int width = scanner.nextInt();
        char[][] cave = new char[height+3][width+3];
        int rowS, colS;
        int rowF, colF;
        for(int i=1;i<=height;i++) {
            String row = scanner.next();
            for(int j=1;j<=width;j++) {
                cave[i][j] = row.charAt(j-1);
            }
        }
        rowS = scanner.nextInt();
        colS = scanner.nextInt();
        Point start = new Point(rowS, colS);
        rowF = scanner.nextInt();
        colF = scanner.nextInt();
        Point finish = new Point(rowF, colF);
        Graph g = new Graph(cave, finish);
        g.bfs(start);
        boolean finishReachable = g.getReachable()[rowF][colF];
        int adjacentSolid = g.countSolid(finish);
        if(start.equals(finish)) {
            if(adjacentSolid>=1)
                System.out.println("YES");
            else
                System.out.println("NO");
            return;
        }
        if(g.adjacent(start, finish)) {
            if(cave[rowF][colF] == 'X'){
                System.out.println("YES");
                return;
            }
            if(adjacentSolid>=1) {
                System.out.println("YES");
                return;
            }
            else {
                System.out.println("NO");
                return;
            }
        }
        if(finishReachable == false) {
            System.out.println("NO");
            return;
        }
        if(cave[rowF][colF] == 'X') {
            System.out.println("YES");
        }
        else {
            if(adjacentSolid>=2)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
        //System.out.println(finishReachable);

    }
}


 class Graph {

    private boolean[][] reachable;
    private char[][] cave;
    private int height;
    private int width;
    private Point finish;

    private final static int[] rowDir = {0, 1, 0, -1};
    private final static int[] colDir = {1, 0, -1, 0};

    public Graph(char[][] cave, Point finish) {
        this.cave = cave;
        this.height = cave.length-3;
        this.width = cave[0].length-3;
        reachable = new boolean[height+3][width+3];
        this.finish = finish;
    }
     public boolean adjacent(Point p1, Point p2) {

         for(int i=0;i<4;i++) {
             Point p3 = new Point(p1.getRow()+rowDir[i], p1.getCol()+colDir[i]);
             if(p2.equals(p3))
                 return true;
         }
         return false;
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

 class Point {
    private int row;
    private int col;

    public Point(int row, int col) {
        this.row = row;
        this.col = col;
    }

    public int getRow() {
        return row;
    }

    public int getCol() {
        return col;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return row == point.row && col == point.col;
    }

    @Override
    public int hashCode() {
        return Objects.hash(row, col);
    }
}
