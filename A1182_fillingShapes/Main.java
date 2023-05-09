import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int n;
        final int MAX_N= 60;
        int[] dp = new int[MAX_N+5];
        Scanner scanner = new Scanner(System.in);
        n= scanner.nextInt();
        int res;
        if(n<2)
            res=0;
        else if(n%2!=0)
            res=0;
        else
            res=(int)Math.pow(2,(n/2));

        System.out.println(res);



    }
}
