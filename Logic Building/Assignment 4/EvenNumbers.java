import java.util.*;

class EvenNumbers{

public static void main(String args[]){

EvenNumbers.even();
}

static void even(){

Scanner sc = new Scanner(System.in);

System.out.println("Enter nmber : ");
int num = sc.nextInt();

for(int i=1;i <= num;i++){

if(i%2 == 0){
System.out.println(i);

}
}

}

}