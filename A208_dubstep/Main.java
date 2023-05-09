import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String remixed = scanner.nextLine();
        String wub = "WUB";
        String res="";
        boolean wasFirstWord = false;

        for(int i= 0;i<remixed.length();i++) {
            if(i+3-1<remixed.length() && remixed.substring(i,i+3).equals(wub)) {
                i+=2;
                continue;
            }

            if(wasFirstWord && i-3>=0 && remixed.substring(i-3,i+3-3).equals(wub))
                res+=" ";
            res+=remixed.charAt(i);
            wasFirstWord = true;
        }

        System.out.println(res);

    }
}
