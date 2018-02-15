#ifndef SCORE_H
#define SCORE_H

#include<QGraphicsTextItem>
#include<QFont>
#include<QDebug>
#include"Const_Def.h"

class Score : public QGraphicsTextItem
{
public:
    Score();
    ~Score(){};
    void increase();

private:
    int score;
};

#endif // SCORE_H
