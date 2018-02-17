#ifndef SCORE_H
#define SCORE_H

#include<QGraphicsTextItem>
#include<QFont>
#include<QDebug>
#include"const_def.h"

class Score : public QGraphicsTextItem
{
public:
    Score();
    int getScore() const {return _score;}
    void increase();

private:
    int _score;
};

#endif // SCORE_H
