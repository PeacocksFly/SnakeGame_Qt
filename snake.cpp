#include "snake.h"

Snake::Snake(GameDirector * gameDirector):
    QGraphicsPixmapItem(),
    GameObject(gameDirector),
    _timer(new QTimer(this)),
    _moveStatus(Qt::Key_Right)
{

    gameDirector->attachGameObject(this);
   //set timer interval to 1 sec
   _timer->setInterval(100);

   //connect the timeout signal from timer to the move function
   connect(_timer, SIGNAL(timeout()), this, SLOT(move()));

   //trigger the timer
   _timer->start();


}

Snake::~Snake()
{
 //   delete _timer;
 //   for (unsigned int i=0 ; i < snakeBody.size(); i++)
 //   {
//         scene->removeItem(snakeBody[i]);
 //      delete snakeBody[i];
//    }

}

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

    QPointF currentPos = QPointF(this->x(), this->y());
    setPos(this->x()+x, this->y()+y);
    if(!snakeBody.empty()) {
        snakeBody.back()->setPos(currentPos);
        snakeBody.push_front(snakeBody.back());
        snakeBody.back() = nullptr;
        snakeBody.pop_back();
    }


   QList<QGraphicsItem *> list = collidingItems();
   if(isItemCollision<Mouse>(list)){

         SnakeBit* body = new SnakeBit(currentPos);
         snakeBody.push_front(body);
         _gameDirector->notifyMouseSwallow(body);
         return;
    }

    if(isWallCollision() ||  isItemCollision<Snake>(list) ){

        _timer->stop();
        quitGame();

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



//returns opposite key
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


void Snake::quitGame(){

  int response = QMessageBox::question(nullptr, "Game Over", "Would you like to restart?", QMessageBox::Yes | QMessageBox::No);

  if (response == QMessageBox::Yes){
                qApp->exit(const_reboot);
   }
   else if (response == QMessageBox::No){
                qApp->exit(0);
   }
}


