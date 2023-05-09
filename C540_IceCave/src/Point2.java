import java.util.Objects;

public class Point2 {
    private int row;
    private int col;

    public Point2(int row, int col) {
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
        Point2 point = (Point2) o;
        return row == point.row && col == point.col;
    }

    @Override
    public int hashCode() {
        return Objects.hash(row, col);
    }
}
