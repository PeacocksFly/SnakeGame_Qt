#ifndef SNAKEBIT_H
#define SNAKEBIT_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include"const_def.h"


class SnakeBit : public QGraphicsPixmapItem
{
public:
    SnakeBit(const QPointF&,
             const qreal& w=const_step_move,
             const qreal& h=const_step_move);

private:
    QPointF _pos;
    int _width;
    int _height;

};

#endif // SNAKEBIT_H
