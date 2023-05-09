import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static int k,n ;
    private static int[] copySeq;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        int[] seq = new int[n+2];

        for(int i=1;i<=n;i++) {
            seq[i] = scanner.nextInt();
        }
        copySeq = seq.clone();
        Arrays.sort(copySeq,1,n+1);
        //System.out.println(Arrays.toString(seq));
        int l=1, r = n;
        int mid =0 ;
        while(l<r) {
             mid = (l+r)/2;
          //  System.out.println("We are going to check: "+l+" + "+r+" /2 = "+mid);
            if(check(seq, mid) == true) {
             //   System.out.println("Works, we want smaller or equal");
                r=mid;
            }
            else {
              //  System.out.println("Doesn't work, we need higher");
                l=mid+1;
            }
        }
        mid = (l+r)/2;
        System.out.println(copySeq[mid]);
    }

    public static boolean check(int[] seq, int idx) {
        int upperBound = copySeq[idx];
        //check if max of odd indices can be at most seq[idx]
        int currentOddSize=0;
        for(int i=1;i<=n;i++) {
            if(currentOddSize%2 == 0) {
                if(seq[i]<=upperBound) {
                    currentOddSize++;
                    continue;
                }
            }
            else {
                currentOddSize++;
            }
        }
        //check if max of even indices can be at most seq[idx]
        int currentEvenSize=0;
        for(int i=1;i<=n;i++) {
            if(currentEvenSize%2 == 1) {
                if(seq[i]<=upperBound) {
                    currentEvenSize++;
                    continue;
                }
            }
            else {
                currentEvenSize++;
            }
        }
       // System.out.println("Odd: "+currentOddSize+" even: "+currentEvenSize);
        return (currentOddSize >= k || currentEvenSize>=k);
    }
}