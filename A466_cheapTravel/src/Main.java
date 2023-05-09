import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfTravels = scanner.nextInt();
        int howManyRides = scanner.nextInt();
        int singleRide = scanner.nextInt();
        int multipleRide = scanner.nextInt();

        if(howManyRides*singleRide<=multipleRide) {
            System.out.println(numberOfTravels*singleRide);
            return;
        }
        int res=0;
        res+=numberOfTravels/howManyRides * multipleRide;
        int rest = numberOfTravels%howManyRides;
        if(rest*singleRide<=multipleRide) {
            res+=rest*singleRide;
        }
        else
            res+=multipleRide;

        System.out.println(res);

    }
}
