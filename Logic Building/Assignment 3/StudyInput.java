import java.util.Scanner;


class StudyInput{

public static void main(String args[]){
StudyInput.sumOfTwoNum();

}


static void sumOfTwoNum (){
Scanner sc = new Scanner(System.in);

System.out.println("Enter Your First Number : ");
int num1 = sc.nextInt();

System.out.println("Enter Your Second Number : ");
int num2 = sc.nextInt();

int sum = num1 + num2;

System.out.println("Sum Of Two Numbers is " + sum);


}

}