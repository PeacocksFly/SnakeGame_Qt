#include "mouse.h"
#include "snake.h"

Mouse::Mouse(GameDirector* gameDirector, const int& x, const int& y, const int& w, const int& h):
    QGraphicsPixmapItem(),
    GameObject(gameDirector),
    _xpos(x),
    _ypos(y),
    _width(w),
    _height(h){
      gameDirector->attachGameObject(this);
}


void Mouse::update(QGraphicsItem* bit){

      mouseReposition();

}


void Mouse::mouseReposition()
{
    do{
        //generate random positions between screen max length and width
        _xpos = (rand() % const_rand_num_x) * const_step_move;
        _ypos = (rand() % const_rand_num_y) * const_step_move;
        setPos(_xpos,_ypos);
    }while(!(collidingItems().empty()));
}


//create and set music when snake hits the mouse
//   hitmouse = new QMediaPlayer;
//   hitmouse->setMedia(QUrl::fromLocalFile("Music/hitmouse.mp3"));






