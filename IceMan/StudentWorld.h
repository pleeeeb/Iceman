#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include <string>

class Actor;

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir);
    virtual ~StudentWorld();
    
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    
      // Add an actor to the world.
    void addActor(Actor* a);
    
      // Clear a 4x4 region of Ice.
    void clearIce(int x, int y);

      // Can actor move to x,y?
    bool canActorMoveTo(Actor* a, int x, int y) const
    {
        if (x > VIEW_WIDTH || y > VIEW_HEIGHT)
        {
            return false;
        }
        return true;
    }

      // Annoy all other actors within radius of annoyer, returning the
      // number of actors annoyed.
    int annoyAllNearbyActors(Actor* annoyer, int points, int radius);

      // Reveal all objects within radius of x,y.
    void revealAllNearbyObjects(int x, int y, int radius);

      // If the IceMan is within radius of a, return a pointer to the
      // IceMan, otherwise null.
    Actor* findNearbyIceMan(Actor* a, int radius) const;

      // If at least one actor that can pick things up is within radius of a,
      // return a pointer to one of them, otherwise null.
    Actor* findNearbyPickerUpper(Actor* a, int radius) const;

      // Annoy the IceMan.
    void annoyIceMan();

      // Give IceMan some sonar charges.
    void giveIceManSonar();

      // Give IceMan some water.
    void giveIceManWater();

      // Is the Actor a facing toward the IceMan?
    bool facingTowardIceMan(Actor* a) const;

      // If the Actor a has a clear line of sight to the IceMan, return
      // the direction to the IceMan, otherwise GraphObject::none.
    GraphObject::Direction lineOfSightToIceMan(Actor* a) const;

      // Return whether the Actor a is within radius of IceMan.
    bool isNearIceMan(Actor* a, int radius) const;

      // Determine the direction of the first move a quitting protester
      // makes to leave the oil field.
    GraphObject::Direction determineFirstMoveToExit(int x, int y);

      // Determine the direction of the first move a hardcore protester
      // makes to approach the IceMan.
    GraphObject::Direction determineFirstMoveToIceMan(int x, int y);
};

#endif // STUDENTWORLD_H_

//#ifndef STUDENTWORLD_H_
//#define STUDENTWORLD_H_
//
//#include "GameWorld.h"
//#include "GameConstants.h"
//#include <string>
//
//// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
//
//class StudentWorld : public GameWorld
//{
//public:
//	StudentWorld(std::string assetDir)
//		: GameWorld(assetDir)
//	{
//	}
//
//	virtual int init()
//	{
//		return GWSTATUS_CONTINUE_GAME;
//	}
//
//	virtual int move()
//	{
//		// This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
//		// Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
//		decLives();
//		return GWSTATUS_PLAYER_DIED;
//	}
//
//	virtual void cleanUp()
//	{
//	}
//    
//
//
//private:
//};
//
//#endif // STUDENTWORLD_H_
