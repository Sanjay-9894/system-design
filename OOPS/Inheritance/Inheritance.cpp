#include <iostream>
#include <string>

using namespace std;

class Car{
    protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

    public:
    Car(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn= false;
        currentSpeed = 0;
    }

    void startEngine(){
        isEngineOn = true;
        cout << brand << " " << model <<" "<< "engine on" << endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << ": Engine turned off <<endl";
    }

      void accelerate() { 
        if (!isEngineOn) {
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake() { 
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    virtual ~Car() {}
};

class ManualCar : public Car{
    private : 
        int currentGear;

    public : 
    ManualCar(string b,string m) : Car(b,m){
        currentGear =0;
    }

    void shiftGear(int gear){
        currentGear = gear;
        cout << "shifted gear to :" << gear << endl;
    }
};


int main(){

    ManualCar* mymanualcar = new ManualCar("suzuki","alto");
    mymanualcar->startEngine();
    mymanualcar->shiftGear(1); //specific to manual car
    mymanualcar->accelerate();
    mymanualcar->stopEngine();

    delete mymanualcar;

    return 0;
}