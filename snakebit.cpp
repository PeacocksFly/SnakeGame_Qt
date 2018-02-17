#include "snakebit.h"

SnakeBit::SnakeBit(const qreal& x, const qreal& y, const qreal& w, const qreal& h):
    QGraphicsPixmapItem(),
    xpos(x),
    ypos(y),
    width(w),
    height(h),
    movestatus(Qt::Key_Right)
{
   //set snake bit size and attach a picture
   setPos(xpos,ypos);
   QPixmap mousepic(QPixmap("Images/snakehead.png"));
   setPixmap(mousepic.scaled(width,height,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

SnakeBit::~SnakeBit()
{}

//retrieve key (arrows) and set the movestatus
void SnakeBit::keyPressEvent(QKeyEvent *event)
{
   Qt::Key key = static_cast<Qt::Key>(event->key());
   //prevent the snake from moving backward
   if (key != opposite_key(movestatus))
   {
       movestatus = key;
   }
}

//movestatus getter
const Qt::Key& SnakeBit::getMoveStatus() const
{
   return movestatus;
}

//movestatus setter
void SnakeBit::setMoveStatus(const Qt::Key& mvtstatus)
{
    movestatus = mvtstatus;
}

//returns opposite key
Qt::Key SnakeBit::opposite_key(const Qt::Key& mvtstatus)
{
    if (mvtstatus== Qt::Key_Right)
         {return Qt::Key_Left;}
    else if (mvtstatus== Qt::Key_Left)
         {return Qt::Key_Right;}
    else if (mvtstatus== Qt::Key_Up)
         {return Qt::Key_Down;}
    else
         {return Qt::Key_Up;}
}






