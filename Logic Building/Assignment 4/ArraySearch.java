import java.util.*;

class ArraySearch{

public static void main(String args[]){

ArraySearch.display();
}

static void display(){

Scanner sc = new Scanner(System.in);

System.out.print("Enter number to search : ");
int num = sc.nextInt();

int[] arr = {40,12,21,14,34};

boolean a = false;

for(int n : arr){

System.out.print(n + " ");

if(n == num){
a = true;

}

}

System.out.println();

if(a == true){
System.out.print("The number is found...");

}else{
System.out.print("The number is not found...");

}

}

}