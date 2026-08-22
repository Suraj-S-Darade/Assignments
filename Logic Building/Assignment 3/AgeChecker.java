import java.util.Scanner;

class AgeChecker {

    public static void main(String args[]) {

        AgeChecker.ageCheck();

    }

    static void ageCheck() {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter your age : ");
        int age = sc.nextInt();

        if (age >= 18) {

            System.out.println("You are Adult...");

        } else {

            System.out.println("You are teenager...");

        }
    }
}