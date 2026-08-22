import java.util.Scanner;

class MultiplyByThree{

public static void main(String args[]){
MultiplyByThree.numbers();
}

static void numbers(){

Scanner sc = new Scanner(System.in);

System.out.print("Enter number : ");
int num = sc.nextInt();

for(int i = 1;i <= num; i++){
 if(i%3 == 0){
System.out.println(i);
}

}

}

}