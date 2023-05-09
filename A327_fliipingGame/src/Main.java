import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] x = new int[n];
        int startsum=0;
        for(int i=0;i<n;i++) {
            x[i] = scanner.nextInt();
            if(x[i]==1)
                startsum++;
        }

        int left=0;
        int right=0;
        int bestRes=-1;
        int curZeros = x[0]==0 ? 1 : 0;


        while(right<n) {
            bestRes=Math.max(bestRes,2*curZeros-(right-left+1));

            if(2*curZeros<=right-left+1) {
                right++;
                left = right;
                curZeros=0;
            }
            else
                right++;

            if(right<n&&x[right]==0)
                curZeros++;


        }
        bestRes=Math.max(bestRes,2*curZeros-(right-left+1));


        System.out.println(startsum+bestRes);



    }
}