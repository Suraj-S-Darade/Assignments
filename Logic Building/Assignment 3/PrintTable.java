import java.util.Scanner;


class PrintTable{

public static void main(String args[]){

PrintTable.table();

}

static void table(){

Scanner sc = new Scanner(System.in);

System.out.print("Enter number.... ");
int num = sc.nextInt();

for(int i = 1; i <= 10; i++){
System.out.println(num + " * " + i + " = " + (num*i));

}

}

}