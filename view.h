#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <typeinfo>
#include "gameobject.h"
#include "gamedirector.h"

class View: public QGraphicsView, public GameObject{

public:
    View(QGraphicsScene* scene, GameDirector* gameDirector):
        QGraphicsView(scene),
        GameObject(gameDirector){
          gameDirector->attachGameObject(this);
    }

};

#endif // VIEW_H
