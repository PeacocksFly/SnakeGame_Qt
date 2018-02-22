#ifndef MOUSE_H
#define MOUSE_H

#include<QGraphicsPixmapItem>
#include<cstdlib>
#include"const_def.h"
#include "gameobject.h"
#include <QMediaPlayer>


class Mouse: public QGraphicsPixmapItem, public GameObject{

public:
    Mouse(GameDirector*);
    ~Mouse();
    virtual void update(QGraphicsItem* bit);
    virtual void reset();


private:
    QMediaPlayer *hitmouse;
    void scream();
    void mouseReposition();

};
#endif // MOUSE_H
