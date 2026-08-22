import java.util.Scanner;

class PrintNum{

public static void main(String args[]){
PrintNum.numbers();
}

static void numbers(){

Scanner sc = new Scanner(System.in);

System.out.println("Enter number : ");
int num = sc.nextInt();

for(int i = 1;i <= num; i++){
System.out.println(i);

}

}

}