#include "score.h"

Score::Score(GameDirector* gameDirector):
    QGraphicsTextItem(),
    GameObject(gameDirector),
    _score(0){
    gameDirector->attachGameObject(this);
}


//increase score when catching a mouse
void Score::update(){
    _score++;
    setPlainText("Mickeys: " + QString::number(_score));
}

