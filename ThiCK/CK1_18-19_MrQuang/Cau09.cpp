#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

class Random {
private:
    static Random* instance;
    Random() {
        srand(time(NULL));
    }
public:
    static Random* getInstance() {
        if (instance == NULL) {
            cout << "instance created.\n";
            instance = new Random();
        }
            
        return instance;
    }
    static int Next() {
        return rand();
    }
    static int Next(int ceiling) {
        return rand() % ceiling;
    }
    static int Next(int floor, int ceiling) {
        return rand() % (ceiling - floor) + floor;
    }
    static void destroyInstance() {
        cout << "destroyInstance.\n";
        if (instance != NULL) {
            delete instance;
            instance = NULL;
        }
        cout << "Random da duoc huy.\n";
    }

    ~Random() {
        cout << "destructor.\n";
        if (instance != NULL) {
           
        }
    }
};

Random* Random::instance = NULL;

int main() {
    system("cls");
    Random* ran1 = Random::getInstance();
    
    for (int i = 0; i < 10; i++) {
        int num = Random::Next(10,20);
        cout << num << endl;
    }
       
    cout << "----------------------------------\n";
    cout << ran1->getInstance() << endl;
    Random* ran2 = Random::getInstance();
    cout << ran2->getInstance() << endl;
    ran1->destroyInstance();
   
    return 0;
}