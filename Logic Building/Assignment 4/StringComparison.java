class StringComparison {

public static void main(String[] args) {

String str1 = new String("hello");
String str2 = new String("hello");

boolean a = false;

boolean b = false;

if(str1 == str2){
a = false;
System.out.println("Using == : " + a);

}else {
a = true;
System.out.println("Using == : " + a);

}

if(str1.equals(str2)){
b = true;
System.out.println("Using == : " + a);

}else {
b = false;
System.out.println("Using == : " + a);

}

//System.out.println("Using .equals() : " + str1.equals(str2));

}

}