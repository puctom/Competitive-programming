import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //https://codeforces.com/problemset/problem/61/E?locale=en
        Scanner scanner = new Scanner(System.in);
        HashMap<Integer, Integer> mapping = new HashMap<>();
        int n = scanner.nextInt();
        int[] powers = new int[n+3];
        long[] greaterLeft = new long[n+3];
        long[] lessRight = new long[n+3];
        long res =0;

        for(int i=1;i<=n;i++) {
            powers[i] = scanner.nextInt();
        }
        int[] temp = powers.clone();
        Arrays.sort(temp,1,n+1);
       // System.out.println(Arrays.toString(temp));

        int count = 1;
        for(int i=1;i<=n;i++) {
            mapping.put(temp[i],count);
            count++;
        }

        for(int i=1;i<=n;i++) {
            powers[i] = mapping.get(powers[i]);
        }

      //  System.out.println(Arrays.toString(powers));

        SegmentTree segmentTreeGr = new SegmentTree(n);

        for(int i=1;i<=n;i++) {
            //System.out.println("We process solider no. " + i + " with power: " + powers[i]);
            greaterLeft[i]=segmentTreeGr.getValue(powers[i]);
            segmentTreeGr.update(1,powers[i]-1,1);
        }

       // System.out.println(Arrays.toString(greaterLeft));

        SegmentTree segmentTreeLe = new SegmentTree(n);

        for(int i=n;i>=1;i--) {
            //System.out.println("We process solider no. " + i + " with power: " + powers[i]);
            lessRight[i]=segmentTreeLe.getValue(powers[i]);
            segmentTreeLe.update(powers[i]+1,n,1);
        }
       // System.out.println(Arrays.toString(lessRight));
        for(int i=1;i<=n;i++) {
            res+=(greaterLeft[i]*lessRight[i]);
        }
        System.out.println(res);
    }
}

 class SegmentTree {

    private int[] tree;
    private final int firstLeave;
    public SegmentTree(int n) {
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
