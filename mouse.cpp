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


void Mouse::update(){


}


void Mouse::mouse_position_generator(const std::deque<SnakeBit*>& snake)
{
    bool flag;
    do{
        //generate random positions between screen max length and width
        _xpos = (rand() % const_rand_num_x) * const_step_move;
        _ypos = (rand() % const_rand_num_y) * const_step_move;
        setPos(_xpos,_ypos);
        //check if new mouse position not on the snake
        flag = collidesWithSnake(snake, scenePos());
    }while(flag==true);
}


//create and set music when snake hits the mouse
//   hitmouse = new QMediaPlayer;
//   hitmouse->setMedia(QUrl::fromLocalFile("Music/hitmouse.mp3"));

//return true if element position collides with snake
bool Mouse::collidesWithSnake(const std::deque<SnakeBit*>& snake, const QPointF& pos)
{
   for(unsigned int i=0; i<snake.size(); i++)
    {
        if (snake[i]->scenePos()==pos)
        {
            return true;
        }
    }
    return false;
}




