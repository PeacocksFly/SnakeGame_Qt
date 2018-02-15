#ifndef MOUSE_H
#define MOUSE_H

#include<QGraphicsPixmapItem>
#include<cstdlib>
#include<QDebug>
#include<deque>
#include<QPointF>
#include "snakebit.h"
#include"Const_Def.h"

class Mouse: public QGraphicsPixmapItem
{
public:
    Mouse(const int& x=const_initial_mouse_pos_x, const int& y=const_initial_mouse_pos_y, const int& w=const_step_move, const int& h=const_step_move);
    ~Mouse(){};
    void mouse_position_generator(const std::deque<SnakeBit*>& snake);
    bool collidesWithSnake(const std::deque<SnakeBit*>& snake, const QPointF& pos);

private:
    int xpos;
    int ypos;
    int width;
    int height;
};
#endif // MOUSE_H
