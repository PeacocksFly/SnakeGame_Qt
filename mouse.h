#ifndef MOUSE_H
#define MOUSE_H

#include<QGraphicsPixmapItem>
#include<cstdlib>
#include<QDebug>
#include<deque>
#include<QPointF>
#include "snakebit.h"
#include"const_def.h"
#include "gameobject.h"

class Mouse: public QGraphicsPixmapItem, public GameObject
{
public:
    Mouse(const int& x=const_initial_mouse_pos_x,
          const int& y=const_initial_mouse_pos_y,
          const int& w=const_step_move,
          const int& h=const_step_move);

    QPointF getPos()const {return QPointF(_xpos, _ypos);}
    int getWidth()  const {return _width;}
    int getHeight() const {return _height;}

    void mouse_position_generator(const std::deque<SnakeBit*>& snake);
    bool collidesWithSnake(const std::deque<SnakeBit*>& snake, const QPointF& pos);

private:
    int _xpos;
    int _ypos;
    int _width;
    int _height;
};
#endif // MOUSE_H
