#include "Score.h"

Score::Score():
    QGraphicsTextItem(),
    score(0)
{
    //set snake score
    setPlainText("Mickeys: " + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("arial",20));
}

//increase score when catching a mouse
void Score::increase()
{
    score++;
    setPlainText("Mickeys: " + QString::number(score));
}

