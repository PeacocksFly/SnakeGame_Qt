#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <typeinfo>

class View: public QGraphicsView{

public:
    View(QGraphicsScene* scene ): QGraphicsView(scene){}

};

#endif // VIEW_H
