#include "score.h"

Score::Score(GameDirector* gameDirector):
    QGraphicsTextItem(),
    GameObject(gameDirector),
    _score(0){
    gameDirector->attachGameObject(this);
}


//increase score when catching a mouse
void Score::update(QGraphicsItem* bit){
    _score++;
    setPlainText("Mickeys: " + QString::number(_score));
}

//reset score to zero after game over
void Score::reset(){
    _score = 0;
    setPlainText("Mickeys: " + QString::number(_score));
}


