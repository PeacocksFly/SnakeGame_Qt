#ifndef GAMEDIRECTOR_H
#define GAMEDIRECTOR_H

#include <QGraphicsScene>
#include "const_def.h"
#include "gameobject.h"
#include <QDebug>

class GameDirector{

public:
    static GameDirector* getInstance();
    void attachGameObject(GameObject*);
    void notifyMouseSwallow(QGraphicsItem* bit);

private:
    GameDirector();
    static GameDirector* _gameDirector;
    QList<GameObject*> _listGameObjects;

};


#endif // GAMEDIRECTOR_H
