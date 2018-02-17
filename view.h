#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <typeinfo>
#include "gameobject.h"

class View: public QGraphicsView{

public:
    View(QGraphicsScene* scene ): QGraphicsView(scene){}

};

#endif // VIEW_H
