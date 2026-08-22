import java.util.*;

class Palindrome{
public static void main(String args[]){

Scanner sc = new Scanner(System.in);

System.out.println("Enter a name : ");
String name = sc.nextLine();

boolean result = true;

for(int i = 0; i <= name.length() -1; i++){

char a = name.charAt(i);
char b = name.charAt(name.length() - 1 - i);

if(a != b){

result = false;

}

}

if(result){

System.out.println("The name " + "(" + name + ")" + " is palindrome");

}else{

System.out.println("The name " + name + " is not palindrome");

}


}

}