#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class NhanVat{
    private:
    string Ten;
    int count;
};

void DocVaVietFile5(string input){
    //========================================= Doc file
    ifstream fin(input);
    if (!fin){
        cout << "Can't open " << input << " to read!" << endl;
        exit(1);
    }
    cout << "Sucessfully open " << input << " to read!" << endl; 
    int n = 0;
    string line;
    string minName;
    int min = 0;
    
    while(!fin.eof()){
        getline(fin, line);
        stringstream ss(line);
        string temp;
        while(!ss.eof()){
            getline(ss,temp,' ');
        }
        int size = temp.size();
        
        if (size > min){
            min = size;
            minName = temp;
        }
       
    } 
        
    //========================================= Viet file
    string output = "output.txt";
    ofstream fout(output);
    if(!fout){
        cout << "Can't open " << output << " to write!" << endl;
        exit(1);
    }
    cout << "Sucessfully open " << output << " to write!"<< endl;
    fout << minName << " " << min << endl;

    fin.close();
    fout.close();
}

int main(){
    string input = "input.txt";
    NhanVat a;
    while(1){
        system("cls");
        a;
        DocVaVietFile5(input);
        system("pause");
    }
    return 0;
}