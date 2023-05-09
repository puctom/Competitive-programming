public class SegmentTree2 {

    private int n ;
    private int[] tree;
    private final int firstLeaf;
    private int[] height;

    public SegmentTree2(int n, int[] height) {
        this.height = height;
        this.n=n;
        int base;
        for(base= 0; (1<<base)<n; base++);
        //System.out.println(base);
        firstLeaf=1<<base;
        tree = new int[(1<<(base+1))];
        initializeTree();
    }

    public int getMinIdx(int l, int r) {
        l+=firstLeaf;
        r+=firstLeaf;
        int res = tree[l];
        if(l!=r) {
            if(height[tree[r]] < height[res] )
                res = tree[r];
        }
        while(l/2 != r/2) {
            if(l%2==0) {
                if(height[tree[l+1]] < height[res])
                    res=tree[l+1];
            }
            if(r%2==1)
                if(height[tree[r-1]] < height[res])
                    res= tree[r-1];

            l/=2; r/=2;
        }
        return res;
    }

    public int getHeight(int idx) {
        return height[idx];
    }

    public void initializeTree() {
        for(int i=0;i<firstLeaf;i++) {
            if(i<n)
                 tree[i+firstLeaf] = i;
            else
                tree[i+firstLeaf] = n;
        }
        for(int i=firstLeaf-1;i>=1;i--) {
            if(height[tree[2*i]] > height[tree[2*i+1]])
                tree[i] = tree[2*i+1];
            else
                tree[i] = tree[2*i];
        }



    }



 }
