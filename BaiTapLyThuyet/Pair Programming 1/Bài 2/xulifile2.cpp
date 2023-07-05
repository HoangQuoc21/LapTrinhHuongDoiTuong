#include<iostream>
#include"PhanSo.h"
#include<fstream>
using namespace std;



PhanSo* Docfile(int&n, string filename)
{
    PhanSo* result=NULL;
    ifstream fin;
    fin.open(filename); 
    if(!fin.is_open())
    {
        cout<<"Mo file that bai."<<endl;
        n=0;
        return result;
    }

    fin>>n;
    result=new PhanSo[n];

    for(int i=0;i<n;i++)
    {
        int tu=0;
        int mau=0;
        fin>>tu;
        fin>>mau;
        result[i].setTu(tu);
        result[i].setMau(mau);
    }
    fin.close();
    return result;
}

int main()
{
    int n=0;
    PhanSo* result = Docfile(n,"INPUT2.txt");
    PhanSo sum;
    for(int i=0;i<n;i++)
    {
        sum=sum+result[i];
    }
    ofstream fout;
    fout.open("OUTPUT2.txt");
    fout<<sum.getTu()<<' '<<sum.getMau()<<'\n';
    fout.close();
    return 1;
}