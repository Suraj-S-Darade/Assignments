class GradeChecker {

public static void main(String args[]) {

       int num1 = 60;
       int num2 = 75;
       int num3 = 85;

       float average = (num1+num2+num3)/3;

        if (average >= 90) {

            System.out.println("Grade A");

        } else if (average >= 70) {

            System.out.println("Grade B");

        } else if (average >= 50) {

            System.out.println("Grade C");

        } else if (average >= 30) {

            System.out.println("Grade D");

        } else {

            System.out.println("Fail");

        }

    }

}