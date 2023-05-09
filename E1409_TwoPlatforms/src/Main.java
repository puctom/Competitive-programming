import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();

        for(int i=0;i<t;i++) {
            int n = scanner.nextInt();
            int k = scanner.nextInt();
            int[] x = new int[n+2];
            int[] toLeft = new int[n+2];
            int[] toRight = new int[n+2];


            for(int j=1;j<=n;j++) {
                x[j] = scanner.nextInt();
            }
            int redundant;
            for(int j=1;j<=n;j++)
                redundant=scanner.nextInt();
            Arrays.sort(x, 1, n+1);
          //  System.out.println(Arrays.toString(x));
            int idxR=n;
            int idxL=1;

            for(int j=1;j<=n;j++) {
                while(x[j]-x[idxL]>k)
                    idxL++;

               // System.out.println("j = " + j + ", idxL = " + idxL);

                toLeft[j] = j - idxL+1;
                if(j>1) toLeft[j] = Math.max(toLeft[j],toLeft[j-1]);
            }

            for(int j=n;j>=1;j--) {
                while(x[idxR]-x[j]>k)
                    idxR--;

                toRight[j]=idxR-j+1;
                if(j<n) toRight[j]=Math.max(toRight[j],toRight[j+1]);
            }
            int ans =0;
            for(int j=1;j<n;j++) {
                ans = Math.max(ans, toLeft[j]+toRight[j+1]);
            }
            if(n==1)
                ans=1;

            //System.out.println(Arrays.toString(toLeft));
            //System.out.println(Arrays.toString(toRight));

            System.out.println(ans);

        }



    }
}