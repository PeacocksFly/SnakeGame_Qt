#ifndef SNAKE_H
#define SNAKE_H

#include "const_def.h"
#include "snakebit.h"
#include <QGraphicsPixMapItem>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QRectF>
#include <deque>
#include <QMediaPlayer>
#include "gamedirector.h"
#include "mouse.h"
#include "snakegame.h"
#include "gameobject.h"
#include <QMessageBox>


class Snake : public QObject, public QGraphicsPixmapItem, public GameObject{
    Q_OBJECT

public:
    Snake(GameDirector* );
    ~Snake();    
    void one_step_move(const qreal& x, const qreal& y, const Qt::Key& movestatus);
    void oneStepMove(const qreal& x, const qreal& y);

    Qt::Key opposite_key(const Qt::Key&);
    void keyPressEvent(QKeyEvent*);

    template<typename T> bool isItemCollision(const QList<QGraphicsItem *>&);
    bool isWallCollision();


private:
    QTimer* _timer;
    Qt::Key _moveStatus;
    std::deque<SnakeBit*> snakeBody;
  //  QMediaPlayer *hitmouse;
   void quitGame();

public slots:
    void move();

};



template<typename T>
bool Snake::isItemCollision(const QList<QGraphicsItem *>& list){
    for(auto it = list.begin(); it!= list.end(); it++)
        if (typeid(**it)  == typeid(T))
            return true;
    return false;
}


#endif // SNAKE_H
