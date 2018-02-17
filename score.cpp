#include "score.h"

Score::Score():
    QGraphicsTextItem(),
    _score(0){
}


//increase score when catching a mouse
void Score::increase(){
    _score++;
    setPlainText("Mickeys: " + QString::number(_score));
}

