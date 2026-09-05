#include <iostream>
#include <memory>

using namespace std;

class Shader{

    string name;
    string type;

    public:

    Shader(string name,string type):name(name),type(type){
        cout << "Shader compiled "<< endl;
    }

    ~Shader(){
        cout << "Shader Destroyed" << endl;
    }

    int getReferenceCount(shared_ptr<Shader> &s){
        return s.use_count();
    }

};

int main(){

shared_ptr<Shader> shader = make_shared<Shader>("main_vert", "vertex");
cout << "Ref count: " << shader -> getReferenceCount(shader) << endl;   
{
shared_ptr<Shader> rendererRef = shader;
cout << "Ref count: " << shader -> getReferenceCount(shader) << endl;

shared_ptr<Shader> editorRef = shader;
cout << "Ref count: " << shader -> getReferenceCount(shader) << endl;


cout << "Ref count: " << shader -> getReferenceCount(shader) << endl; 

    return 0;
}