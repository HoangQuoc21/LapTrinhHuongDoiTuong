#include <iostream>
#include <cmath>
using namespace std;

class CPoint{
private:
    int x;
    int y;
public:
    CPoint(){
        x = y = 0;
    }
    int GetX(){ return x; }
    int GetY(){ return y; }
    void SetX(int X){x = X;}
    void SetY(int Y){y = Y;}
    double DistanceTo(const CPoint& other){
        return sqrt(pow(x-other.x,2)+pow(y-other.y,2));
    }
};

int main(){
    system("cls");
    CPoint c;
    CPoint c1;
    c1.SetX(1);
    c1.SetY(1);
    cout << c1.DistanceTo(c) << endl;
    return 0;
}