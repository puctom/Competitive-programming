import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        tests:
        for(int i=0;i<t;i++) {
            int n = scanner.nextInt();
            int[] a = new int[n+3];

            for(int j=1;j<=n;j++)
                a[j] = scanner.nextInt();
            int[] aSaved = a.clone();

            boolean wasSwapped = false;
            int[] prev = new int[2];
            for(int j=1;j<=n-1;j++) {
                System.out.println("before j = " + j + ", a[] = " + Arrays.toString(a));
                if(j == n-1 && a[j] == a[j+1]) {
                    System.out.println("YES");
                    continue tests;
                }
                if(a[j] <= a[j+1] )
                    a[j+1] -=a[j];
                else {
                    if(wasSwapped == true) {
                        break;
                    }
                    else {
                        if(j == 1) {
                            a[j+1] = a[j] - a[j+1];
                            System.out.println("-- swapped --");

                        }
                        else {
                            if(a[j+1]>=prev[0]) {
                                a[j+1] = prev[1] - (a[j+1] - prev[0]);
                                wasSwapped = true;
                                System.out.println("-- swapped --");
                            }
                            else
                                break;
                        }


                    }
                }


                prev[0] = a[j];
                prev[1] = a[j+1];
                System.out.println("after j = " + j + ", a[] = " + Arrays.toString(a));
            }
            a = aSaved;
            wasSwapped = false;
            for(int j=n;j>=2;j--) {
                System.out.println("before j = " + j + ", a[] = " + Arrays.toString(a));
                if(j == 2 && a[j] == a[j-1]) {
                    System.out.println("YES");
                    continue tests;
                }
                if(a[j] <= a[j-1] )
                    a[j-1] -=a[j];
                else {
                    if(wasSwapped == true) {
                        break;
                    }
                    else {
                        if(j == n) {

                            a[j-1] = a[j] - a[j-1];
                            System.out.println("-- swapped --");
                        }
                        else {
                            if(a[j-1]>=prev[0]) {
                                a[j-1] = prev[1] - (a[j-1] - prev[0]);
                                wasSwapped = true;
                                System.out.println("-- swapped --");
                            }
                            else
                                break;
                        }


                    }
                }


                prev[0] = a[j];
                prev[1] = a[j-1];
                System.out.println("after j = " + j + ", a[] = " + Arrays.toString(a));
            }
            System.out.println("NO");



        }
    }
}