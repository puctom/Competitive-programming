import java.util.Scanner;
import  java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        int students;
        int puzzles;
        int MAX_PUZZLES = 50;
        int[] difficulty = new int[MAX_PUZZLES];

        Scanner scanner = new Scanner(System.in);
        students = scanner.nextInt();
        puzzles = scanner.nextInt();
        for(int i=0;i<puzzles; i++) {
            difficulty[i] = scanner.nextInt();
        }

        Arrays.sort(difficulty, 0 , puzzles);
       // System.out.println(Arrays.toString(difficulty));
        int res=Integer.MAX_VALUE;
        int tempres;
        for(int i=0; i<puzzles-students+1; i++) {
            tempres = difficulty[i+students-1]-difficulty[i];

            if(tempres<res)
                res=tempres;
        }

        System.out.println(res);


    }
}
