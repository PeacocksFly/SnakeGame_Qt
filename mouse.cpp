#include "mouse.h"
#include "snake.h"

Mouse::Mouse(GameDirector* gameDirector):
    QGraphicsPixmapItem(),
    GameObject(gameDirector),
    hitmouse(new QMediaPlayer){

      gameDirector->attachGameObject(this);      
      hitmouse->setMedia(QUrl::fromLocalFile("Music/hitmouse.mp3"));
}

Mouse::~Mouse(){

     delete hitmouse;
}


//update the position after
void Mouse::update(QGraphicsItem* bit){

      scream();
      mouseReposition();
}

void Mouse::reset() {

    setPos(const_initial_mouse_pos_x, const_initial_mouse_pos_y);
}

//check if the new recalculated position is not colling any other scene object
void Mouse::mouseReposition(){

    int xpos, ypos;
    do{
        xpos = (rand() % const_rand_num_x) * const_step_move;
        ypos = (rand() % const_rand_num_y) * const_step_move;
        setPos(xpos, ypos);
    }while(!(collidingItems().empty()));

}

void Mouse::scream(){

    if(!hitmouse) return;

    if(hitmouse->state()==QMediaPlayer::PlayingState)
          hitmouse->setPosition(0);
    hitmouse->play();

}






