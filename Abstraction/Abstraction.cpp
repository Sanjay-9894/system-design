#include <iostream>
#include <String>
using namespace std;

class Car{
    public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
};

class SportsCar : public Car{
    public:
    string brand;
    string model;
    bool isEngineOn;
    int currentGear;
    int currentSpeed;

    SportsCar(string b,string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentGear =0;
        currentSpeed = 0;
     
    }

    void startEngine(){
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void shiftGear(int gear) {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot Shift Gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }
};

int main(){
    Car* mycar = new SportsCar("ford","mustang");
    mycar->startEngine();
    mycar->shiftGear(1);
    mycar->accelerate();

    delete mycar;
    return 0;
}