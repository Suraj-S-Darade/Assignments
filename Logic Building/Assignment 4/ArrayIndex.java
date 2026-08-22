import java.util.*;

class ArrayIndex{

public static void main(String args[]){

ArrayIndex.display();
}

static void display(){

Scanner sc = new Scanner(System.in);

System.out.print("Enter number to search : ");
int num = sc.nextInt();

int[] arr = {40,12,21,14,34};

int index = -1;

boolean a = false;

for(int i = 0; i <= arr.length -1; i++){

if(arr[i] == num){
a = true;
index = i;
}

}

if(a == true){
System.out.println("The index is : " + index);
System.out.println("The number is : " + num);

}else{
System.out.println("The number not found");
}

}

}