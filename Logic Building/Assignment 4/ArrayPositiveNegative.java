import java.util.*;

class ArrayPositiveNegative{

public static void main(String args[]){

ArrayPositiveNegative.display();
}

static void display(){

int[] arr = {40,-12,21,-14,34};

int positive = 0;

int negative = 0;

for(int i = 0 ; i <= arr.length -1 ; i++){

if(arr[i] > 0){
positive++;
}

if(arr[i] < 0){
negative++;
}

}

System.out.println("The positive number count : " + positive);

System.out.println("The negative number count : " + negative);

}

}