import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String x = scanner.nextLine();
        char[] xChars = x.toCharArray();
        boolean wasNonZero = false;
        for (int i = 0; i < x.length(); i++) {

            if (xChars[i] >= '5' && (xChars[i]!='9' || wasNonZero))
                xChars[i] = (char) ('0' + '9' - xChars[i]);

            if(xChars[i]!=9)
                wasNonZero = true;
        }
        String res = new String(xChars);
        Long ans = Long.parseLong(res);
        if(ans==0)
            ans=9l;
        System.out.println(ans);
    }
}
