import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        int n,k;
        for(int i=0;i<t;i++) {
            n = scanner.nextInt();
            k = scanner.nextInt();

            if(n%2 == 1 && k%2 == 0) {
                System.out.println("NO");
                continue;
            }

            if(n%2 == 0) {
                if(k>n ||(k==n-1 &&n!=2)) {
                    System.out.println("NO");
                    continue;
                }
                else {
                    if(k%2 == 1 && k>n/2 ) {
                        System.out.println("NO");
                        continue;
                    }
                    System.out.println("YES");
                    if(k>n/2) {
                        for(int j=0;j<k-1;j++)
                            System.out.print("1 ");
                        System.out.println(n-(k-1));
                    }
                    else {
                        for(int j=0;j<k-1;j++) {
                            System.out.print("2 ");
                        }
                        System.out.println(n-2*(k-1));
                    }
                }
            }
            else {
                if(k>n) {
                    System.out.println("NO");
                    continue;
                }
                System.out.println("YES");
                for(int j=0;j<k-1;j++)
                    System.out.print("1 ");
                System.out.println(n-(k-1));
            }



        }
    }
}