#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
class StudentWorld;

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class Actor: public GraphObject {
public:
    
    Actor(int imageID, int startX, int startY, Direction startDirection, float size = 1.0, unsigned int depth = 0, StudentWorld* world): GraphObject(imageID, startX, startY, startDirection, size, depth) {
        this->world = world;
    };
    
    virtual ~Actor() {};
    
    virtual void doSomething() = 0;
    
    //TESTING COMMIT TO MUHAMMAD_S_BRANCH2

    
    virtual StudentWorld* getWorld() {return world;}
// GraphObject(int imageID, int startX, int startY,
// DIRECTION startDirection, float size = 1.0,
//unsigned int depth = 0);
//    void setVisible(bool shouldIDisplay);
//    void getX() const;
//    void getY() const;
//    void moveTo(int x, int y);
//    DIRECTION getDirection() const; // Directions: up, down, left, right
//    void setDirection(DIRECTION d); // Directions: up, down, left, right
    
private:
    StudentWorld* world;
    double healthPoints;
};

class IceMan: public Actor {
    
public:
    IceMan(StudentWorld* world): Actor(IID_PLAYER, 30, 60, right, 1, 0, 10, world) {
        setVisible(true);
    }
    
    virtual void doSomething() override {}
    
    virtual bool isAlive() {}
    
    int setLife() {}
    
    int getGoldNuggs() const;
    
    int getWaterInInventory() const;
    
    int getSonarKits() const;
    
    void setGoldNuggs(int newGold) { goldNuggs += newGold; }
    
    void setSonarKits(int newSonar) { SonarKits += newSonar; }
    
    void setWaterStored(int newWater) { WaterStored += newWater; }
    
    
    
private:
    int goldNuggs = 0;
    int WaterStored = 5;
    int SonarKits = 1;
    int healthPoints = 5;
    
};

class RegularProtester: public Actor {
    
    // GraphObject(IID_PROTESTER, 60, 60, left, 1.0, 0)
    
    RegularProtester(int imageID, int healthPoints, StudentWorld* world);
    
    
    virtual void doSomething() override {
        
        if (NextToIceman() ) {
            
        }
        
        else if (IcemanIsVisible() ) {
            
        }
        
        else if (NextToIce() ) {
            
        }
        
        else {
            switch (getDirection()) {
                case up:
                    moveTo(getX(), getY() + 1);
                    break;
                    
                case down:
                    moveTo(getX(), getY() - 1);
                    break;
                    
                case left:
                    moveTo(getX() - 1, getY());
                    
                case right:
                    moveTo(getX() + 1, getY());
                    break;
                    
                case none:
                    break; // both default and none mean the protestor doesnt move
                default:
                    break;
            }
            
        }
        
    };
    
    virtual bool NextToIceman();
    
    virtual bool IcemanIsVisible();
    
    virtual bool NextToIce();
    
    
private:
    
};

class HardcoreProtester: public RegularProtester {
    
};

class Items: public GraphObject {
    
    
};

class GoldNugget: public Items {
    
};



#endif // ACTOR_H_
