class SumOfNumbers{

public static void main(String args[]){

SumOfNumbers.sum();
}

static void sum(){

int sum = 0;

for(int i=1;i<=5;i++){

sum = sum + i;

}

System.out.print("Total Sum is : " + sum);

}

}