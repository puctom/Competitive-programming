import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        for(int i=0;i<t;i++) {
            int n = scanner.nextInt();
            int[] a = new int[n];
            for(int j=0;j<n;j++)
                a[j] = scanner.nextInt();

            int res = 0;
            int last, howMany;
            last = 0;
            howMany = 1;

            res = a[0];

            for(int j=1;j<n;j++) {
                if(howMany == 2) {
                    if(last == 0) {
                        last = 1;
                    }
                    else {
                        last = 0;
                        res = res + (a[j] == 1 ? 1: 0);
                    }
                    howMany=1;

                }
                else {
                    if(last == 0) {
                        if(a[j]==0) {
                            if(j+1<n && a[j+1] == 0) {
                                last = 1;
                                continue;
                            }
                            else {
                                howMany++;
                                continue;
                            }
                        }
                        else {
                            last = 1;
                        }
                    }
                    else {
                        if(a[j]==0) {
                            last = 0;
                        }
                        else {
                            howMany++;
                        }
                    }
                }
            }

            System.out.println(res);


        }

    }
}