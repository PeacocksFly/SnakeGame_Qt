#ifndef GAMEDIRECTOR_H
#define GAMEDIRECTOR_H

#include <QGraphicsScene>
#include "const_def.h"
#include "gameobject.h"
#include <QApplication>
#include <QMessageBox>


class GameDirector{

public:
    static GameDirector* getInstance();
    void attachGameObject(GameObject*);
    void notifyMouseSwallow(QGraphicsItem*);
    void notifyGameOver();

private:
    GameDirector();
    static GameDirector* _gameDirector;
    QList<GameObject*> _listGameObjects;

};

#endif // GAMEDIRECTOR_H
