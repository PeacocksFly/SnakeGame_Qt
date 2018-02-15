#include "Mouse.h"
#include "Snake.h"

Mouse::Mouse(const int& x, const int& y, const int& w, const int& h):
    QGraphicsPixmapItem(),
    xpos(x),
    ypos(y),
    width(w),
    height(h)
{
    //position the mouse and attach a picture
    setPos(xpos,ypos);
    setPixmap(QPixmap("Images/mouse.jpg").scaled(width,height,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void Mouse::mouse_position_generator(const std::deque<SnakeBit*>& snake)
{
    bool flag;
    do{
        //generate random positions between screen max length and width
        xpos = (rand() % const_rand_num_x) * const_step_move;
        ypos = (rand() % const_rand_num_y) * const_step_move;
        setPos(xpos,ypos);
        //check if new mouse position not on the snake
        flag = collidesWithSnake(snake, scenePos());
    }while(flag==true);
}

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


