#include "snake.h"

Snake::Snake(QGraphicsScene *scene, Mouse *mouse, Score *score):
    scene(scene),
    mouse(mouse),
    score(score),
    timer(new QTimer(this))
{
   //create head snake object
   SnakeBit* head = new SnakeBit(const_initial_head_snake_x,const_initial_head_snake_x);
   snake.push_back(head);
   head = nullptr;
   //put focus on the head
   snake.front()->setFlag(QGraphicsItem::ItemIsFocusable);
   snake.front()->setFocus();
   //add head snake to the scene
   scene->addItem(snake.front());

   //set timer interval to 1 sec
   timer->setInterval(100);

   //connect the timeout signal from timer to the move function
   connect(timer, SIGNAL(timeout()), this, SLOT(move()));

   //trigger the timer
   timer->start();

   //create and set music when snake hits the mouse
   hitmouse = new QMediaPlayer;
   hitmouse->setMedia(QUrl::fromLocalFile("Music/hitmouse.mp3"));
}

Snake::~Snake()
{
    //release memory
    delete timer;
    for (unsigned int i=0 ; i < snake.size(); i++)
    {
       scene->removeItem(snake[i]);
       delete snake[i];
    }
    delete hitmouse;
    scene = nullptr;
    mouse = nullptr;
    score = nullptr;
}

void Snake::move()
{
    //check the movestatus of snake head and give the direction
    if(snake.front()->getMoveStatus()==Qt::Key_Right){
       one_step_move(const_step_move, 0, Qt::Key_Right);
    }
    else if(snake.front()->getMoveStatus()==Qt::Key_Left){
       one_step_move(-const_step_move, 0, Qt::Key_Left);
    }
    else if(snake.front()->getMoveStatus()==Qt::Key_Up){
       one_step_move(0, -const_step_move, Qt::Key_Up);
    }
    else if(snake.front()->getMoveStatus()==Qt::Key_Down){
       one_step_move(0, const_step_move, Qt::Key_Down);
    }
}



void Snake::one_step_move(const qreal& x, const qreal& y, const Qt::Key &movestatus)
{
    //first case: snake collides with bounds or itself -> stop the game
    if ( (snake.front()->x()+x) >= const_length ||
         (snake.front()->x()+x) < 0    ||
         (snake.front()->y()+y) < 0    ||
         (snake.front()->y()+y) >= const_width  ||
         (mouse->collidesWithSnake(snake, QPointF((snake.front()->x()+x), (snake.front()->y()+y)))))
    {
        timer->stop();
        int response = QMessageBox::question(nullptr, "Game Over", "Would you like to restart?", QMessageBox::Yes | QMessageBox::No);

        if (response == QMessageBox::Yes)
        {
            qApp->exit(const_reboot);
        }
        else if (response == QMessageBox::No)
        {
            qApp->exit(0);
        }
    }

    //second case: snake catches a mouse
    else if (QPointF((snake.front()->x()+x), (snake.front()->y()+y))==(mouse->scenePos()))
    {
        if (snake.front())
        {
            //play hit music and rewind if still playing after catching a mouse
            if (hitmouse->state() == QMediaPlayer::PlayingState)
            {
               hitmouse->setPosition(0);
               hitmouse->play();
            }
            else
            {
               hitmouse->play();
            }

            SnakeBit* body = new SnakeBit((snake.front()->x()+x),(snake.front()->y()+y));
            snake.push_front(std::move(body));
            body = nullptr;
            scene->addItem(snake.front());
            score->increase();
            snake.front()->setFlag(QGraphicsItem::ItemIsFocusable);
            snake.front()->setFocus();
            snake.front()->setMoveStatus(movestatus);
            mouse->mouse_position_generator(snake);
        }
    }
    //third case: snake moving
    else
    {   if (snake.front())
        {
            snake.back()->setPos((snake.front()->x()+x), (snake.front()->y()+y));
            snake.push_front(snake.back());
            snake.back() = nullptr;
            snake.pop_back();
            snake.front()->setFocus();
            snake.front()->setMoveStatus(movestatus);
        }
    }
}

