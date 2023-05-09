import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        long[][] dist = new long[n+3][n+3];
        long[] ans = new long[n+3];
        int[] del = new int[n+3];
        boolean[] usable = new boolean[n+3];

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++)
                dist[i][j] = scanner.nextLong();
        }

        for(int i=1;i<=n;i++)
            del[i] = scanner.nextInt();


        for(int i=n;i>=1;i--) {

            int newest = del[i];
            //System.out.println("Now we can use "+ newest + "vertex");
            usable[newest] = true;
            for(int k=1;k<=n;k++) {
                for(int l=1;l<=n;l++) {
                    dist[k][l] = Math.min(dist[k][l], dist[k][newest] + dist[newest][l]);

                    if(usable[k] && usable [l]) {
                        ans[i]+=dist[k][l];
                    }
                }


            }
        }

        for(int i=1;i<=n;i++)
            System.out.print(ans[i] + " ");


    }
}