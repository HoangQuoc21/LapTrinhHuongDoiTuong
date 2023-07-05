#include<iostream>
#include"PhanSo.h"
#include<fstream>
#include<stdio.h>
using namespace std;
#define Max 100


void DocFile(PhanSo result[],int& n)
{
    freopen("INPUT3.txt","rt",stdin);
    while (!cin.eof())
    {
        int tu=0;
        int mau=0;
        cin>>tu;
        cin>>mau;
        PhanSo temp(tu,mau);
        result[n].setTu(tu);
        result[n].setMau(mau);
        n++;
    }
    
}


int main ()
{
    PhanSo result[Max];
    int n=0;
    DocFile(result,n);
    PhanSo sum;
    for(int i=0;i<n;i++)
    {
        sum=sum+result[i];
    }
    freopen("OUTPUT3.txt","wt",stdout);
    cout<<sum.getTu()<<'/'<<sum.getMau()<<'\n';
   
    return 0;
}