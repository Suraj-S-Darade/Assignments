import java.util.*;

class OddNumbers{

public static void main(String args[]){

OddNumbers.odd();
}

static void odd(){

Scanner sc = new Scanner(System.in);

System.out.println("Enter nmber : ");
int num = sc.nextInt();

int sum = 0;

for(int i=1;i <= num;i++){

if(i%2 != 0){
sum = sum + i;
}

}

System.out.println("Odd number's total sum is : " + sum);


}

}