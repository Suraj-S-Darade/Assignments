#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

using Header = pair<string, string>; 
using HeaderList = vector<Header>; 
using Port = unsigned int; 
using IPAddress  = string;

typedef unsigned long long RequestId;

void printHeaders(const HeaderList& Headers){

    for(int i = 0; i < Headers.size(); i++ ){
        cout << Headers[i].first << ":" << Headers[i].second << endl;
    }
    
}

int main(){
    
    Port port = 8080;
    RequestId ID = 123456789;
    HeaderList headers = {

        {"Content-Type ", " application/json"},
        {"Authorization ", " Bearer eyJhbGci..."},
        {"Accept-Language ", " en-US"}

    };

    cout << "Request ID   : " << ID << endl;
    cout << "Server Port  : " << port << endl;

    cout << "Headers:" << endl;

    printHeaders(headers);

    return 0;
}