#include<iostream>
#include"PhanSo.h"
#include<vector>
#include<fstream>
using namespace std;

vector<PhanSo> DocFile(string filename)
{
    vector<PhanSo> result;
    ifstream fin;
    fin.open(filename); 
    if(!fin.is_open())
    {
        cout<<"Mo file that bai."<<endl;
        return result;
    }

    while (!fin.eof())
    {
        int tu=0;
        int mau=0;
        fin>>tu;
        fin>>mau;
        PhanSo temp(tu,mau);
        result.push_back(temp);
    }
    fin.close();
}




int main()
{
    vector<PhanSo> result =DocFile("INPUT1.txt");
    PhanSo tong = result[0]+result[1];
    ofstream fout;
    fout.open("OUTPUT1.txt");
    fout<<tong.getTu()<<' '<<tong.getMau();
    fout.close();
    return 1;
}
