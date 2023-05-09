import java.util.Comparator;

public class EdgePair2 implements Comparable<EdgePair> {
    private int dest;
    private long weight;
    private boolean isTrain;

    public EdgePair2(int dest, long weight, boolean isTrain) {
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
        if(costThis>costThat)
            return 1;
        if(costThis<costThat)
            return -1;
        if(this.isTrain() == true)
            return -1;
        else
            return 0;
    }
}
