#include "snake.h"

Snake::Snake(GameDirector * gameDirector):
    QGraphicsPixmapItem(),
    GameObject(gameDirector),
    _timer(new QTimer(this)),
    _moveStatus(Qt::Key_Right){

    gameDirector->attachGameObject(this);

   //set up and connect a timer for the snake to move
   _timer->setInterval(100);
   connect(_timer, SIGNAL(timeout()), this, SLOT(move()));
   _timer->start();
}

Snake::~Snake()
{
      delete _timer;
      if (scene()){
          for (unsigned int i=0 ; i < snakeBody.size(); i++){
                   scene()->removeItem(snakeBody[i]);
                   delete snakeBody[i];
           }
      }
}

//called any timeout signal
void Snake::move()
{
    //check the movestatus of snake head and give the direction
    if(_moveStatus==Qt::Key_Right){
       oneStepMove(const_step_move, 0);
    }
    else if(_moveStatus==Qt::Key_Left){
       oneStepMove(-const_step_move, 0);
    }
    else if(_moveStatus==Qt::Key_Up){
       oneStepMove(0, -const_step_move);
    }
    else if(_moveStatus==Qt::Key_Down){
       oneStepMove(0, const_step_move);
    }
}


void Snake::oneStepMove(const qreal& x, const qreal& y){

    //reset the snake position
    QPointF currentPos = QPointF(this->x(), this->y());
    setPos(this->x()+x, this->y()+y);
    if(!snakeBody.empty()) {
        snakeBody.back()->setPos(currentPos);
        snakeBody.push_front(snakeBody.back());
        snakeBody.back() = nullptr;
        snakeBody.pop_back();
    }


    //check if any colliding items
    QList<QGraphicsItem *> list = collidingItems();

    //if mouse hit game director is notified to update scene objects
    if(isItemCollision<Mouse>(list)){

          SnakeBit* body = new SnakeBit(currentPos);
          snakeBody.push_front(body);
          if(_gameDirector)
                 _gameDirector->notifyMouseSwallow(body);
          return;
     }

     //game director notification in case of game over
     if(isWallCollision() ||  isItemCollision<SnakeBit>(list) ){
         if(_timer)
             _timer->stop();
         if(_gameDirector)
             _gameDirector->notifyGameOver();
     }

}

bool Snake::isWallCollision(){

   if (scene())
      if(!(scene()->sceneRect().contains(pos())))
        return true;
    return false;

}

//retrieve key (arrows) and set the movestatus
void Snake::keyPressEvent(QKeyEvent *event)
{
   Qt::Key key = static_cast<Qt::Key>(event->key());
   //prevent the snake from moving backward
   if (key == opposite_key(_moveStatus))
       return;

    _moveStatus = key;

}

Qt::Key Snake::opposite_key(const Qt::Key& mvtstatus)
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

void Snake::reset(){

    if (scene()){
        for (unsigned int i=0 ; i < snakeBody.size(); i++){
                 scene()->removeItem(snakeBody[i]);
                 if (snakeBody[i])
                    delete snakeBody[i];
         }
    }
    snakeBody.clear();
    _moveStatus = Qt::Key_Right;
    setPos(const_initial_head_snake_x,const_initial_head_snake_x);
    if(_timer) _timer->start();
}

