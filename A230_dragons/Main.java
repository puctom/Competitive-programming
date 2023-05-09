import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Arrays;
public class Main {
    public static void main(String[] args) {

        int s;
        int n;

        final int MAX_N = 1000;
        int[][] dragons = new int [MAX_N][2];


        Scanner scanner = new Scanner(System.in);

        s=scanner.nextInt();
        n=scanner.nextInt();

        for(int i=0;i<n;i++) {
            dragons[i][0] = scanner.nextInt();
            dragons[i][1] = scanner.nextInt();
        }

        Arrays.sort(dragons, 0, n, Comparator.comparingInt(a -> a[0]));

        for(int i=0;i<n;i++) {
            if(s<=dragons[i][0]) {
                System.out.println("NO");
                return;
            }

            s+=dragons[i][1];
        }
        System.out.println("YES");
        //System.out.println(Arrays.toString(dragons[0]));



    }
}
