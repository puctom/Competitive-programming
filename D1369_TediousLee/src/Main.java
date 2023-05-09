import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final int maxN = 2*1_000_000+5;
        final int mod = 1_000_000_000+7;
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int[] dp = new int[maxN];
        int[] r = new int[maxN]; // 0 - root uncoloured, 1 - root coloured
        dp[1] = 0; r[1] = 0;
        dp[2] = 0; r[2] = 0;
        for(int i=3;i<=maxN-5;i++) {
            r[i] = 0;
            dp[i] = dp[i-1] +  dp[i-2];
            dp[i] = dp[i] % mod;
            dp[i] += dp[i-2];
            if((r[i-1]-1)*(r[i-2]-1)!=0) {
                dp[i]+=4;
                r[i]=1;
            }
            dp[i] = dp[i] % mod;
        }
        int q;
        for(int i=0;i<t;i++) {
            q= scanner.nextInt();
            System.out.println(dp[q]);
        }
    }
}