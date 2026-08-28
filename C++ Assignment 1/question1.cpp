#include <iostream>
using namespace std;

int temperature(double range){
   if(range < 0){
    return -1;
   }
   if(range >=0 && range <= 29){
    return 0;
   }
   if(range >=30 && range <= 44){
    return 1;
   }
  if(range >=45 && range <= 59){
    return 2;
   }
  else{
    return 3;
   }

}


void status(int statusCode){
   
    switch(statusCode){

        case -1:
        cout << "Status : SENSOR_ERROR" << endl;
        cout << "Action : Sensor fault -- check wiring" << endl;
        break;

        case 0:
        cout << "Status : NORMAL" << endl;
        cout << "Action : No action required" << endl;
        break;

        case 1:
        cout << "Status : WARNING" << endl;
        cout << "Action : Alert send to supervisor" << endl;
        break;

        case 2:
        cout << "Status : CRITICAL" << endl;
        cout << "Action : Cooling system triggered" << endl;
        break;

        case 3:
        cout << "Status : SHUTDOWN" << endl;
        cout << "Action : Emergency shutdown initiated" << endl;
        break;
    }
}





int main(){
  double range;
  
  cout << "Enter temperature : ";
  cin >> range;

  int statusCode = temperature(range);

  string reading = (range > 25) ? "Above Average" : "Below Average" ;

  double Fahrenheit = (range * 9 / 5) + 32;

  cout << "Temperature : " << range << " / " << Fahrenheit << endl;
  status(statusCode);
  cout << "Reading : " << reading << endl;



  return 0;
}