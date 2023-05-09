import java.util.Scanner;
public class Main {

    public static void main(String[] args) {

        int x;
        Scanner scanner = new Scanner(System.in);
        x = scanner.nextInt();

        System.out.println(countSetBits(x));
    }

    public static int countSetBits(int x) {
        int res=0;
        while(x>0) {
            x = x & (x-1);
            res++;
        }
        return res;
    }
}
