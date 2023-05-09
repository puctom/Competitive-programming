import java.util.ArrayList;
import java.util.List;

public class Node2 {
    private int number;
    public int price;
    private int original;
    private int expected;
    public int extra1 = 0;
    public int extra0 = 0;
    private List<Node> adj = new ArrayList<>();

    public Node2(int number, int price, int original, int expected) {
        this.number = number;
        this.price = price;
        this.original = original;
        this.expected = expected;
    }

    public int getNumber() {
        return number;
    }

    public int getPrice() {
        return price;
    }

    public int getOriginal() {
        return original;
    }

    public int getExpected() {
        return expected;
    }

    public List<Node> getAdj() {
        return adj;
    }


}
