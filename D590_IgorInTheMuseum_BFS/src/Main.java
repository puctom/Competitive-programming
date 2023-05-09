import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                if(st.hasMoreTokens()){
                    str = st.nextToken("\n");
                }
                else{
                    str = br.readLine();
                }
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) {
        //https://codeforces.com/problemset/problem/598/D
        FastReader scanner = new FastReader();

        int rows = scanner.nextInt();
        int columns = scanner.nextInt();
        int t = scanner.nextInt();
        int[][] museum = new int[rows+5][columns+5];
        String s;
        char c='x';
        // s = scanner.nextLine();
        for(int i=1;i<=rows;i++) {
            s = scanner.nextLine();
            //System.out.println(s);
            for(int j=1;j<=columns;j++) {
                c = s.charAt(j-1);
                if(c=='*')
                    museum[i][j] = -1; // -1 - wall
                else
                    museum[i][j] = 0;
            }
        }

        int noRow, noCol;
        Graph G = new Graph(rows, columns, museum);

        G.dobfs();

        for(int i=0;i<t;i++) {
            noRow = scanner.nextInt();
            noCol = scanner.nextInt();

//            System.out.println("We consider cell: row: " + noRow + ", column: " + noCol);
//            System.out.println("Belongs to group: " + G.getGroup(noRow,noCol));
            System.out.println(G.getResult(G.getGroup(noRow,noCol)));


        }

      /*  for(int i=1;i<=rows;i++) {
            for(int j=1;j<=columns;j++) {
                System.out.print(museum[i][j]);
            }
            System.out.println();
        }*/

    }
}

class Graph {
    private int rows;
    private int columns;
    private int[][] museum;
    private int[][] group;

    private int currentGroup=0;
    private ArrayList<Integer> result = new ArrayList<Integer>();

    private static int rowDir[] = {0, 1, 0, -1};
    private static int colDir[] = {1, 0, -1, 0};


    public Graph(int rows, int columns, int[][] museum) {
        this.rows = rows;
        this.columns = columns;
        this.museum = museum;
        this.group = new int[rows+3][columns+3];

    }

    public int getGroup(int row, int column) {
        return group[row][column];
    }

    public int getResult(int idx) {
        return result.get(idx);
    }

    public void dobfs() {

         boolean[][] added = new boolean[rows+3][columns+3];

        for(int i=1;i<=rows;i++) {
            for(int j=1;j<=columns;j++) {
                if(added[i][j] == false && museum[i][j] == 0) {
                    bfs(i,j,added);
                    currentGroup++;
                }




            }
        }
    }
   public void bfs(int row, int column, boolean[][] added) {
        int res = 0;

        //System.out.println("we start considering cell: (" + row +", "+column+")");
       added[row][column] = true;
       //res+=4;

       LinkedList<Point> bfsqueue = new LinkedList<>();
       Point p1 = new Point(row, column);
       bfsqueue.add(p1);


       while(bfsqueue.size()!=0) {

           res+=4;
          // System.out.println("Res increased to :" + res);
           p1 = bfsqueue.poll();
           row = p1.getRow();
           column = p1.getColumn();
           group[row][column] = currentGroup;

          // System.out.println("Row: " + row + ", col: " + column);

           for(int i=0;i<4;i++) {
               if(museum[row+rowDir[i]][column+colDir[i]] == 0) {
              //     System.out.println("Neighbour: (" + (row + rowDir[i]) + ", " + (column + colDir[i]) + ") is empty ");
                   res--;
               //      System.out.println("Res decreased to :" + res);
                   if (added[row + rowDir[i]][column + colDir[i]] == false) {
                       added[row + rowDir[i]][column + colDir[i]] =true;
                        bfsqueue.add(new Point(row + rowDir[i], column + colDir[i]));

                   }
               }

           }

       }

       result.add(res);



   }


}




class Point {
    private int row;
    private int column;

    public Point(int row, int column) {
        this.row = row;
        this.column = column;
    }

    public int getRow() {
        return row;
    }

    public int getColumn() {
        return column;
    }
}


