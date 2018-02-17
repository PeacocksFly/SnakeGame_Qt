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
    SnakeBit(const qreal& x, const qreal& y, const qreal& w=const_step_move, const qreal& h=const_step_move);
    ~SnakeBit();
    const Qt::Key& getMoveStatus() const;
    void setMoveStatus(const Qt::Key& movestatus);
    Qt::Key opposite_key(const Qt::Key& mvtstatus);
    void keyPressEvent(QKeyEvent *event);
private:
    int xpos;
    int ypos;
    int width;
    int height;
    Qt::Key movestatus;
};

#endif // SNAKEBIT_H
