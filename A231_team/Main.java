import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int n;
        n = scanner.nextInt();
        int numberOfTeamMates=3;
        int res=0;
        int[] a = new int[numberOfTeamMates];
        for(int i=0;i<n;i++) {
            int tempSum=0;
            for(int j=0;j<a.length;j++) {
                a[j] = scanner.nextInt();
                tempSum+=a[j];
            }
            if(tempSum>=2)
                res++;
        }

        System.out.println(res);

    }

}
