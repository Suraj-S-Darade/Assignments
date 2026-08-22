import java.util.*;

class ArraySum{

public static void main(String args[]){

ArraySum.sum();
}

static void sum(){

int[] arr = {2,12,21,14,34};

int sum = 0;

for(int n : arr){
System.out.print(n+" ");

}

System.out.println();

for(int i = 0; i <= arr.length - 1; i++){
  
sum = sum + arr[i];

}
System.out.println("Total sum of array is : " + sum);
}

}