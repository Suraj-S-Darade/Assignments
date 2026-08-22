import java.util.*;

class ArraySort{

public static void main(String args[]){

ArraySort.display();
}

static void display(){

int[] arr = {40,-12,21,-14,34};

for(int n : arr){
System.out.print(n + " ");
}

Arrays.sort(arr);

System.out.println(" ");
System.out.print("After ascending order : ");

for(int n : arr){
System.out.print(n + " ");
}

}

}