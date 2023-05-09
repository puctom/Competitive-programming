import java.util.Scanner;
public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int t=scanner.nextInt();
        int n, m;
        final int MAX_NM = 1000;



        for(int i=0;i<t;i++) {
            int[] r = new int[MAX_NM];
            int[] b = new int[MAX_NM];
            n= scanner.nextInt();

            int mSumR = 0;
            int mSumB = 0;
            int tempSumR = 0;
            int tempSumB = 0;

            for(int j=0;j<n;j++) {
                r[j] = scanner.nextInt();
                tempSumR+=r[j];
                if(tempSumR > mSumR)
                    mSumR = tempSumR;
            }
            m=scanner.nextInt();

            for(int j=0;j<m;j++) {
                b[j] = scanner.nextInt();
                tempSumB += b[j];
                if(tempSumB>mSumB)
                    mSumB=tempSumB;
            }

            System.out.println((mSumB+mSumR));
        }

    }
}
