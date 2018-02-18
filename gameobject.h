#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameDirector;

class GameObject{

public:
    GameObject(GameDirector* gameDirector):
          _gameDirector(gameDirector){}
    virtual void update() {}

protected:
    GameDirector* _gameDirector;

};

#endif // GAMEOBJECT_H
