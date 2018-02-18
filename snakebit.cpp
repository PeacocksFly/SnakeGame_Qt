#include "snakebit.h"

SnakeBit::SnakeBit(const QPointF& pos, const qreal& w, const qreal& h):
    QGraphicsPixmapItem(),
    _pos(pos),
    _width(w),
    _height(h)
{
   //set snake bit size and attach a picture
   setPos(_pos);
   QPixmap mousepic(QPixmap("Images/snakebody.png"));
   setPixmap(mousepic.scaled(_width,_height,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}










