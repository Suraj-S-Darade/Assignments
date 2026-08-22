import java.util.Scanner;


class PositiveNumbers{

public static void main(String args[]){

PositiveNumbers.positive();

}

static void positive(){
Scanner sc = new Scanner(System.in);

int num;

do{

System.out.println("Enter number.... ");
num = sc.nextInt();

if(num < 0){
System.out.println("Enter POsitive number....");
}


}while(num <= 0);

System.out.println("Positive number is : " + num);
}

}