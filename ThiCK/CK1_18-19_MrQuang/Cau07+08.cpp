#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <sstream>
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
    string toString(){
        stringstream builder;
        builder << "(" << x << ", " << y << ")";
        string result = builder.str();
        return result;
    }
};

class Random{
public:
    Random(){
        srand(time(NULL));
    }
    int Next(){
        return rand();
    }
    int Next(int ceiling){
        return rand() % ceiling;
    }
    int Next(int floor, int ceiling){
        return rand() % (ceiling - floor) + floor;
    }
};

int main(){
    system("cls");
    Random rand;
    for (int i = 0; i < 20; i++)
        cout << rand.Next(10,20) << endl;
    return 0;
}