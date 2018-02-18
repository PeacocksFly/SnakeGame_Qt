#ifndef SCORE_H
#define SCORE_H

#include<QGraphicsTextItem>
#include<QFont>
#include<QDebug>
#include"const_def.h"
#include "gameobject.h"
#include "gamedirector.h"


class Score : public QGraphicsTextItem, public GameObject{
public:
    Score(GameDirector*);
    int getScore() const {return _score;}
    virtual void update(QGraphicsItem* bit);

private:
    int _score;
};

#endif // SCORE_H
