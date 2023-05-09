import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int q = scanner.nextInt();

        for(int i=0;i<q;i++) {
            int c = scanner.nextInt();
            int m = scanner.nextInt();
            int x = scanner.nextInt();

            System.out.println(Math.min((c+m+x)/3,Math.min(c,m)));
        }


    }
}