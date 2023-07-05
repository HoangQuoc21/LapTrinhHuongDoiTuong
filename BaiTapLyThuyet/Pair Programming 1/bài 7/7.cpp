#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include <cmath>
using namespace std;

float Stof(string a)
{
    float result=0;
    float heSo = 10;
    int i = 0;
    for( i;i<a.size();i++)
    {
        if(a[i] == '.')
            break;
        result = result*heSo + a[i]-'0';
    }
    heSo=0.1;
    for( i;i<a.size();i++)
    {
        result = result*heSo + (a[i]-'0')*heSo;
        heSo*=0.1;
    }
    return result;
}


class NhanVien
{
private:
    float luong;
    string Ten;
    string Phong;
    float heso;
public:
    NhanVien(string,string);
    void setTen(string);
    string getTen();
    void setPhong(string);
    void setheso(float h){
        heso = h;
    }
    void setLuong(float l){
        luong = l;
    }
    float getluong()
    {
        return luong;
    }
    string getPhong();
    string PhongMaxNV(vector<NhanVien>);
};

NhanVien::NhanVien(string Ten_init, string Phong_init)
{
    Ten = Ten_init;
    Phong = Phong_init;
}

void NhanVien::setTen(string Alter)
{
    Ten = Alter;
}

void NhanVien::setPhong(string Alter)
{
    Phong = Alter;
}

string NhanVien::getPhong()
{
    return Phong;
}

string NhanVien::getTen()
{
    return Ten;
}


string reverseStr(string str){   
    string result;
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);

    result = str;
    return result;
}

vector<NhanVien> docFile(string fileName)
{
    vector<NhanVien> result;
    
    freopen("INPUT7.txt","rt",stdin);
    float luongcb=0;
    cin>>luongcb;
    NhanVien temp("","");
    while(!cin.eof())
    {
        string line;
        getline(cin, line);
        string buffer;


        // buffer = line.substr(line.size()-4, line.size()-1);
        line = reverseStr(line);
        stringstream ss(line);
        
        getline(ss, buffer, ' ');
        
        buffer = reverseStr(buffer);
        //cout << "_" << buffer << "_" << endl;
        // float heSo = stof(buffer);
        // luongcb = luongcb*heSo;
        
        
        getline(cin,buffer,' ');
        temp.setPhong(buffer);
        getline(cin,buffer);
        buffer=buffer.substr(0,buffer.size()-3);
        temp.setTen(buffer);
        temp.setLuong(luongcb);
        result.push_back(temp);
    }
    return result;
}
int getMaxPost(float* arr, int n)
{
    int max = 0;
    for( int i=1;i<n;i++)
    {
        if(arr[i]>max)
            max = i;
    }
    return max;
}
string NhanVien::PhongMaxNV(vector<NhanVien> source)
{
    
    int n = source.size();
    float* demNhanVienPhong = new float[n]{0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            if(source[i].Phong==source[j].Phong)
                demNhanVienPhong[i]+=source[j].getluong();
        }
    }
    int maxPost=getMaxPost(demNhanVienPhong,n);
    return source[maxPost].Phong;
}


int main()
{
    vector<NhanVien> doc;
    doc = docFile("INPUT7.txt");
    string phongDongNhat = doc[0].PhongMaxNV(doc);
 


    freopen("OUTPUT7.txt","wt",stdout);

    
    float luong = 0;
    for (int i = 0; i < doc.size(); i++)
        if (doc[i].getPhong()==phongDongNhat)
            luong+= doc[i].getluong();
    cout<< phongDongNhat<< " " << luong*2 << endl;
    for( int i = 0; i < doc.size();i++)
    {   
        if(doc[i].getPhong()==phongDongNhat)
            cout<<doc[i].getTen()<<endl;
    }
    
}