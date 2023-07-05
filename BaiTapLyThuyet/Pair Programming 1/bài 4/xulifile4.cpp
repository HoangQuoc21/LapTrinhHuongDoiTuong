#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Date {
private:
    int _ngay;
    int _thang;
    int _nam;
public:
    Date();
    Date(int ngay, int thang, int nam);

    void setNgaySinh(string thongTin);
    int ngay();
    int thang();
    int nam();
};

Date::Date() {
    _ngay = _thang = _nam = 0;
}

Date::Date(int ngay, int thang, int nam) {
    _ngay = ngay;
    _thang = thang;
    _nam = nam;
}

string reverseStr(string str){   
    string result;
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);

    result = str;
    return result;
}


void Date::setNgaySinh(string thongTin) {
    stringstream ss(thongTin);
    string buffer;
    getline(ss, buffer, '/');
    _ngay = stoi(buffer);
    getline(ss, buffer, '/');
    _thang = stoi(buffer);
    getline(ss, buffer);
    _nam = stoi(buffer);
}


int Date::ngay() {
    return _ngay;
}

int Date::thang() {
    return _thang;
}

int Date::nam() {
    return _nam;
}


ostream& operator<<(ostream& out, Date src) {
    if (src.ngay() < 10)
        out << "0" << src.ngay() << "/";
    else
        out << src.ngay() << "/";

    if (1 + src.thang() < 10)
        out << "0" << src.thang() << "/";
    else
        out << src.thang() << "/";

    out << src.nam();

    return out;
}


class Laptop{
private:
    string ten;
    Date _ngaySinh;
public:
    Laptop();
    Laptop(string, Date);
    string getTen();
    void setTen(string);
    Date getNgay();
    void setDodaiten(int);

    int tinhTuoi(){
        int _tuoi = 2023 - _ngaySinh.nam() - 1;
    if (3 > _ngaySinh.thang())
        _tuoi++;
    else if (3 == _ngaySinh.thang()) {
        if (15 >= _ngaySinh.ngay())
            _tuoi++;
    }
    return _tuoi;
    }
    
    Laptop& operator =(const Laptop& source);
};

string Laptop::getTen()
{
    return ten;
}

Date Laptop::getNgay()
{
    return _ngaySinh;
}

void Laptop::setTen(string alter)
{
    ten = alter;
}



Laptop::Laptop()
{
    ten = "unknow";
    Date ngaymoi;
    _ngaySinh=ngaymoi;
}

Laptop::Laptop(string ten_init, Date ngay_init)
{
    ten=ten_init;
    _ngaySinh=ngay_init;
}



Laptop& Laptop::operator=(const Laptop& source)
{
    this->ten= source.ten;
    this->_ngaySinh=source._ngaySinh;
    return *this;
}



class listnhanvat{
private:
    vector<Laptop> list;
    int n;
public:
    int getN();
    void docfile(string fileName);
    vector<Laptop> getList()
    {
        return list;
    }
    int GetLongest();
};



int listnhanvat::getN()
{
    return n;
}

void listnhanvat::docfile(string filename)
{
    freopen("INPUT4.txt","rt",stdin);

    while (!cin.eof())
    {
        string line;
        getline(cin, line);
        line = reverseStr(line);
        stringstream ss(line);
        string buffer;
        Date dBuffer;
        string buffer2;
        getline(ss,buffer,' ');
        buffer = reverseStr(buffer);
        dBuffer.setNgaySinh(buffer);

        getline(ss, buffer);
        buffer = reverseStr(buffer);
        
        Laptop temp(buffer, dBuffer);
        list.push_back(temp);
    }
    n=list.size();

}


int listnhanvat::GetLongest()
{
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        if(list[i].tinhTuoi() > max)
            max=list[i].tinhTuoi();
    }
    return max;
}

int main()
{
    listnhanvat doc;
    doc.docfile("INPUT4.txt");
    for(int i=0;i<doc.getN();i++)
    {
            cout<<doc.getList()[i].getTen()<<' '<<doc.getList()[i].getNgay() <<'\n';

    }
    int max = doc.GetLongest();

    freopen("OUTPUT4.txt","wt",stdout);
    for(int i=0;i<doc.getN();i++)
    {   
        if (doc.getList()[i].tinhTuoi() == max)
            cout<<doc.getList()[i].getTen()<<' '<<doc.getList()[i].getNgay() <<'\n';

    }
    


    

    return 1;
}




