#include <iostream>
using namespace std;

class WalkableRobot{
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

class NormalWalk : public WalkableRobot{
    public:
    void walk() override{
        cout << "Walking normally" << endl;
    }
};

class Nowalk : public WalkableRobot{
    public:
    void walk() override{
        cout << "cannot walk" << endl;
    }
};

class FlyableRobot {
    public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot{
public:
    void fly() override{
        cout <<"flying normally"<< endl;
    }
};

class NoFly : public FlyableRobot{
public:
    void fly() override{
        cout <<"cannot fly"<< endl;
    }
};

class Robot{
    protected:
    WalkableRobot* walkbehavior;
    FlyableRobot* flyBehavior;

    public:
        Robot(WalkableRobot* w, FlyableRobot* f){
        this->walkbehavior = w;
        this->flyBehavior = f;
    }

    void walk(){
        walkbehavior->walk();
    }

    void fly(){
        flyBehavior->fly();
    }

    virtual void projection() = 0;
};

class CompanionRobot : public Robot{
public:
    CompanionRobot(WalkableRobot* w, FlyableRobot* f)
        :Robot(w,f) {}
    
        void projection() override{
            cout<< "Displaying friendly companion features.." <<endl;
        }
};

int main(){
    Robot* robot1 = new CompanionRobot(new NormalWalk(), new NoFly());
    robot1->walk();
    robot1->fly();
    robot1->projection();

    return 0;
};