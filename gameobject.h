#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "gamedirector.h"

class GameObject{

public:
    GameObject(GameDirector* gameDirector):
               _gameDirector(gameDirector){}
private:
    GameDirector* _gameDirector;
};




#endif // GAMEOBJECT_H
