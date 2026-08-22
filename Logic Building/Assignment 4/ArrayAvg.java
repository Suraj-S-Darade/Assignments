import java.util.*;

class ArrayAvg{

public static void main(String args[]){

ArrayAvg.arrAvg();
}

static void arrAvg(){

int[] arr = {40,12,21,14,34};

int result = 0;

for(int i = 0 ; i <= arr.length -1 ; i++){
result = result + arr[i];
}

float avg = (float) result/arr.length;

System.out.println("The Average Of Array : " + avg);

}

}