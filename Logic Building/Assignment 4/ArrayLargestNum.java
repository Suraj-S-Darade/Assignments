import java.util.*;

class ArrayLargestNum{

public static void main(String args[]){

ArrayLargestNum.arrLarge();
}

static void arrLarge(){

int[] arr = {40,12,21,14,34};

int result = arr[0];

for(int i = 1 ; i <= arr.length -1 ; i++){

if(arr[i] > result){
result = arr[i];

}
   
}

System.out.println("The largest number in Array : " + result);

}

}