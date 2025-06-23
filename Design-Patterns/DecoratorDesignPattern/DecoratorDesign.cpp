#include <iostream>
#include <string>

using namespace std;

class Character{
public:
    virtual string getAbilities() const = 0;
    virtual ~Character() {}
};

class Mario : public Character{
    public:
    string getAbilities() const override{
        return "mario";
    }
};

class CharacterDecorator : public Character{
    protected:
    Character* character;

    public:
    CharacterDecorator(Character* c){
        this->character = c;
    }
};

class HeightUp : public CharacterDecorator{
    public:
    HeightUp(Character* c): CharacterDecorator(c){}

    string getAbilities() const override {
        return character->getAbilities() + " with HeightUp";
    }
};

// Concrete Decorator: Gun Shooting Power-Up.
class GunPowerUp : public CharacterDecorator {
public:
    GunPowerUp(Character* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with Gun";
    }
};

class StarPowerUp : public CharacterDecorator {
public:
    StarPowerUp(Character* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with Star Power (Limited Time)";
    }
    
    ~StarPowerUp() {
        cout << "Destroying StarPowerUp Decorator" << endl;
    }
};

int main(){
    Character* mario = new Mario();
    cout << "basic character" << mario->getAbilities() <<endl;

    mario = new HeightUp(mario);
     cout << "After HeightUp: " << mario->getAbilities() << endl;

     mario = new GunPowerUp(mario);
      cout << "After GunPowerUp: " << mario->getAbilities() << endl;

    delete mario;

    return 0;

}