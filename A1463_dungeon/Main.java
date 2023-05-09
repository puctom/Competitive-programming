import java.util.Scanner;


public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int a,b,c;
        for(int i=0;i<t;i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();

            if((a+b+c)%9 == 0 && Math.min(Math.min(a,b),c)>=(a+b+c)/9) {
                System.out.println("YES");
            }
            else
                System.out.println("NO");



        }

    }
}
