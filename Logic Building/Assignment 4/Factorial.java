import java.util.Scanner;

class Factorial{

public static void main(String args[]){

Factorial.number();

}

static void number(){

Scanner sc = new Scanner(System.in);

System.out.print("Enter number : ");
int num = sc.nextInt();

int result = 1;

for(int i = num;i >= 1; i--){
 result = result * i;

}

System.out.print(result);

}

}


