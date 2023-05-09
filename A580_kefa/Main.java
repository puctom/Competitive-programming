import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        int n;
        final int MAX_N=100_000;

        int[] a = new int[MAX_N];
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        int tempLen = 1;
        int res=0;
        for(int i=0;i<n;i++) {
            a[i] = scanner.nextInt();
            if(i>=1) {
                if(a[i]>=a[i-1])
                    tempLen++;
                else
                    tempLen=1;
            }
            res=Math.max(res, tempLen);

        }

        System.out.println(res);

    }
}
