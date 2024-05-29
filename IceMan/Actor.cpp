#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp
void Actor::moveTo(int x, int y)
{
    if(getWorld()->canActorMoveTo(this, x , y))
    {
        GraphObject::moveTo(x, y);
    }
}
