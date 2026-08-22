import java.util.*;

class Vowels{
public static void main(String args[]){

Scanner sc = new Scanner(System.in);

System.out.println("Enter a name : ");
String name = sc.nextLine();

int count = 0;

for(int i = 0; i <= name.length() -1; i++){
char n = name.charAt(i);

if(n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u'){
  count++;
}

}

System.out.println("Vowels : " + count);
}

}