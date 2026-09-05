#include <iostream>
#include <memory>
using namespace std;

class Texture{
    string name;
    int width;
    int height;

    public:

    Texture(string name,int width,int height):name(name),width(width),height(height){
        cout << "Texture loaded" << endl;
    }

    ~Texture(){
        cout << "Texture Release" << endl;
    }

    void diaplay()const{
        cout << "Name : " << name << "Width : " << width << "Height : " << height << endl;
    }
};

int main(){

    unique_ptr<Texture> text1 = make_unique<Texture>("player_sprite",512,512);

    text1 -> diaplay();

    // unique_ptr<Texture> text2 = text1;
    // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = Texture; _Dp = std::default_delete<Texture>]'

    unique_ptr<Texture> text2 = move(text1);

    cout << "tex1 is null: " << (text1 == nullptr ? "YES" : "NO") << endl;


    return 0;
}