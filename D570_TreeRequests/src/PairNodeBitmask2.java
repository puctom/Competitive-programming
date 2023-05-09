public class PairNodeBitmask2 {
    private int preOrder;
    private  int bitmask;

    public PairNodeBitmask2(int preOrder, int bitmask) {
        this.preOrder = preOrder;
        this.bitmask = bitmask;
    }
    public String toString() {
        String res="";
        res="<" + preOrder + ", " + bitmask+">";
        return res;
    }

    public int getPreOrder() {
        return preOrder;
    }

    public void setPreOrder(int preOrder) {
        this.preOrder = preOrder;
    }

    public int getBitmask() {
        return bitmask;
    }

    public void setBitmask(int bitmask) {
        this.bitmask = bitmask;
    }
}
