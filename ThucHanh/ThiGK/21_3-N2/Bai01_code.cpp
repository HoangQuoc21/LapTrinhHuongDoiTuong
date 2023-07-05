#include <iostream>
using namespace std;

class ComplexNum{
private:
    float m_Real;
    float m_Img;
public:
    ComplexNum(){
        m_Real = 0;
        m_Img = 0;
    }
    ComplexNum(float real, float img = 0){
        m_Real = real;
        m_Img = img;
    }
    virtual~ComplexNum(){
        cout << m_Real << "," << m_Img << endl;
    }
};

int main(){
    ComplexNum x(1,9);
    ComplexNum y(5);
    ComplexNum *p;
    p = new ComplexNum(11,13);
    delete p;
    p = &x;
    return 0;
}