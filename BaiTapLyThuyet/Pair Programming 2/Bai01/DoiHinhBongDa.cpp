#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

// Lớp cầu thủ
class Player {
protected:
    
    string position; // Vị trí
    int passing; // Chuyền
    int shooting; // Sút
    int strength; // Sức lực

public:
    string shirt_number; // Số áo
    // Constructor
    Player(string shirt_number, string position, int passing, int shooting, int strength) {
        this->shirt_number = shirt_number;
        this->position = position;
        this->passing = passing;
        this->shooting = shooting;
        this->strength = strength;
    }

    int getPower() {
        return strength;
    }

    string getPosition() {
        return position;
    }

    string getShirt_number() {
        return shirt_number;
    }

    // Phương thức in thông tin cầu thủ
    virtual void print() {
        cout << "Shirt number: " << shirt_number << endl;
        cout << "Position: " << position << endl;
        cout << "Passing: " << passing << endl;
        cout << "Shooting: " << shooting << endl;
        cout << "Strength: " << strength << endl;
    }

    int chuyen() {
        return passing;
    }

    int sut() {
        return shooting;
    }

};

// Lớp cầu thủ dự bị, kế thừa từ lớp Player
class ReservePlayer : public Player {
public:
    // Constructor
    ReservePlayer(string shirt_number, string position, int strength) : Player(shirt_number, position, 8, 8, strength) {}

    // Phương thức in thông tin cầu thủ
    void print() {
        cout << "Reserve player" << endl;
        Player::print();
    }
};

// Lớp cầu thủ thi đấu, kế thừa từ lớp Player
class PlayingPlayer : public Player {
public:
    // Constructor
    PlayingPlayer(string shirt_number, string position, int passing, int shooting, int strength) : Player(shirt_number, position, passing, shooting, strength) {}

    // Phương thức in thông tin cầu thủ
    void print(){
        cout << "Playing player" << endl;
        Player::print();
    }
};

bool hopLe(string s1, string s2, string s3) {
    if (s1 == "TienDao") {
        if (s2 == "TienVe") {
            if (s3 == "ThuMon")
                return true;
        }
        else if (s2 == "ThuMon") {
            if (s3 == "TienVe")
                return true;
        }
    }

    else if (s1 == "TienVe") {
        if (s2 == "TienDao") {
            if (s3 == "ThuMon")
                return true;
        }
        else if (s2 == "ThuMon") {
            if (s3 == "TienDao")
                return true;
        }
    }

    else if (s1 == "ThuMon") {
        if (s2 == "TienVe") {
            if (s3 == "TienDao")
                return true;
        }
        else if (s2 == "TienDao") {
            if (s3 == "TienVe")
                return true;
        }
    }
    return false;
}

int main() {
    // Mở file input để đọc
    freopen("input.txt", "rt", stdin);

    // Đọc các thông tin cầu thủ từ file input
    vector<Player*> players;
    string line;

    while (getline(cin, line)) {
        vector<string> buffer;
        stringstream ss(line);
        while (ss) {
            string b;
            getline(ss, b, ' ');
            buffer.push_back(b);
        }

        if (buffer[0][0] == 'C') {
            players.push_back(new PlayingPlayer(buffer[0], buffer[1] + " " + buffer[2], stoi(buffer[3]), stoi(buffer[4]), stoi(buffer[5])));
        }
        else {
            players.push_back(new ReservePlayer(buffer[0], buffer[1] + " " + buffer[2], stoi(buffer[3])));
        }
    }

    for (auto x : players) {
        //cout << x->getPosition() << " " << x->getShirt_number()  << " " << x->getPower() << endl;
        x->print();
        cout << "---------------------------------------------------------------\n\n";
    }



    freopen("output.txt", "wt", stdout);
    // Tìm đội hình với tổng sức mạnh trên 150
  
    
    int count = 1;

 
    for (int i = 0; i < players.size(); i++) {
        for (int j = i + 1; j < players.size(); j++) {
            for (int k = j + 1; k < players.size(); k++) {
                int tong = (players[i]->getPower() + players[j]->getPower() + players[k]->getPower());
                string s1 = players[i]->getPosition();
                string s2 = players[j]->getPosition();
                string s3 = players[k]->getPosition();
                if ( tong > 150) {
                    players[i]->shirt_number[0] = 'C';
                    players[j]->shirt_number[0] = 'C';
                    players[k]->shirt_number[0] = 'C';
                    cout << count++ << endl;
                    cout << players[i]->getShirt_number() << " " << players[i]->getPosition() << " " <<players[i]->chuyen() << " " << players[i]->sut() << " " << players[i]->getPower() << endl;
                    cout << players[j]->getShirt_number() << " " << players[j]->getPosition() << " " << players[j]->chuyen() << " " << players[j]->sut() << " " << players[j]->getPower() << endl;
                    cout << players[k]->getShirt_number() << " " << players[k]->getPosition() << " " << players[k]->chuyen() << " " << players[k]->sut() << " " << players[k]->getPower() << endl;
                    cout << endl;
                    //cout << players[i]->getShirt_number() << " " << players[j]->getShirt_number() << " " << players[k]->getShirt_number() << " " << tong << endl;
                }
            }
        }
    }

    // Giải phóng bộ nhớ
    for (Player* player : players) {
        delete player;
    }

    return 0;
}
