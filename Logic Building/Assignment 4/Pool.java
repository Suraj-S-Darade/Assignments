class Pool{
public static void main(String args[]){

String str1 = "Hello";
String str2 = str1.intern();

String str3 = "Hello";

System.out.println("IS str2 & str3 pointing to the same object : " + (str2 == str3));

}

}