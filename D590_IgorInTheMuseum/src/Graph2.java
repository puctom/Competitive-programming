import java.util.ArrayList;

public class Graph2 {
    private int rows;
    private int columns;
    private int[][] museum;
    private int[][] group;
    private int currentGroup=0;
    private ArrayList<Integer> result = new ArrayList<Integer>();

    private static int rowDir[] = {0, 1, 0, -1};
    private static int colDir[] = {1, 0, -1, 0};


    public Graph2(int rows, int columns, int[][] museum) {
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

    public void dodfs() {
        boolean[][] visited = new boolean[rows+3][columns+3];
        for(int i=1;i<=rows;i++) {
            for(int j=1;j<=columns;j++) {
                if(visited[i][j] == false && museum[i][j] == 0) {
                    dfs(i,j,visited);
                    currentGroup++;
                }




            }
        }
    }

    public void dfs(int row, int column, boolean[][] visited) {
        Integer res = 0;

        res = dfsUtil(row, column ,visited, res);
        result.add(res);

    }

    public Integer  dfsUtil(int row, int column, boolean[][] visited, Integer res) {
        group[row][column] = currentGroup;
       // System.out.println("we start considering cell: (" + row +", "+column+")");
        visited[row][column] = true;
        res+=4;
        //System.out.println("Res increased to :" + res);
        for(int i=0;i<4;i++) {

            if(museum[row+rowDir[i]][column+colDir[i]] == 0) {
                res--;
              //  System.out.println("Res decreased to :" + res);
                if (visited[row + rowDir[i]][column + colDir[i]] == false) {
                //    System.out.println("Neighbour: (" + (row + rowDir[i]) + ", " + (column + colDir[i]) + ") is empty and not visited");

                    res = dfsUtil(row + rowDir[i], column + colDir[i], visited, res);
                   // System.out.println(res);
                }
            }
        }

      //  System.out.println("Current res: " + res);

        return res;

    }


}
