#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsItem>

class GameDirector;

class GameObject{

public:
    GameObject(GameDirector* gameDirector):
          _gameDirector(gameDirector){}
    virtual void update(QGraphicsItem*) {}

protected:
    GameDirector* _gameDirector;

};

#endif // GAMEOBJECT_H
