public class SegmentTree2 {

    private int[] tree;
    private final int firstLeave;
    public SegmentTree2(int n) {
        int base = (int)Math.ceil(Math.log(n)/Math.log(2));
        tree = new int[(1<<(base+1))+4];
        firstLeave = (1<<base);
    }

    public void update(int left, int right, int value) {
        if(left>right)
            return;
        left = left + firstLeave -1;
        right = right + firstLeave -1;
        tree[left]+=value;
       // System.out.println("We add " + value + " to tree[" + left+"]");
        if(left!=right) {
            tree[right] +=value;
          //  System.out.println("We add " + value + " to tree[" + right+"]");
        }


        while(left/2 != right/2) {
            if(left%2==0) {
                tree[left+1] +=value;
              //  System.out.println("We add " + value + " to tree[" + (left+1)+"]");
            }
            if(right%2==1) {
                tree[right-1]+=value;
               // System.out.println("We add " + value + " to tree[" + (right-1)+"]");
            }

            left/=2;
            right/=2;
        }
    }

    public int getValue(int node) {
        node = firstLeave + node -1;
        int res = 0;
        while(node>0) {
            //System.out.println("We add tree[" + node + "] = " + tree[node]);
            res += tree[node];
            node/=2;
        }
        return res;
    }
}
