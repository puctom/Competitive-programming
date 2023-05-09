import java.lang.Math;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        for(int i=0;i<t;i++) {
            long[] count = new long[32];
            int n = scanner.nextInt();
            for(int j=0;j<n;j++) {
                int x = scanner.nextInt();
                count[(int)Math.ceil(Math.log(x+1)/Math.log(2))]++;
            }
            long res=0;
            for(int j=1;j<32;j++) {
                //System.out.println("count[" + j +" = "+ count[j]);
                res+=count[j]*(count[j]-1)/2;
            }
            System.out.println(res);

        }


    }
}