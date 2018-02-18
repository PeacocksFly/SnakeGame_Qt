#include "standardgamescenebuilder.h"

StandardGameSceneBuilder::StandardGameSceneBuilder():
    GameSceneBuilder(),
    _gameScene(nullptr){
}

void StandardGameSceneBuilder::buildScene(GameDirector* gameDirector){

    if(_gameScene) return;

    _gameScene = new Scene(gameDirector);
    _gameScene->setSceneRect(0,0,const_length,const_width);
}

void StandardGameSceneBuilder::buildView(GameDirector* gameDirector){

    if(!_gameScene->views().empty()) return;

    View* view = new View(_gameScene, gameDirector);

    view->setBackgroundBrush(Qt::green);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(const_length,const_width);
    view->show();
}


void StandardGameSceneBuilder::buildScore(GameDirector* gameDirector){

    if(dynamic_cast<Scene*>(_gameScene)->isItemPresentInScene<Score>()) return;

    Score* score = new Score(gameDirector);
    //display snake score
    score->setPlainText("Mickeys: " + QString::number(score->getScore()));
    score->setDefaultTextColor(Qt::red);
    score->setFont(QFont("arial",20));
    _gameScene->addItem(score);
}

void StandardGameSceneBuilder::buildMouse(GameDirector* gameDirector){

    if(dynamic_cast<Scene*>(_gameScene)->isItemPresentInScene<Mouse>()) return;

    Mouse* mouse = new Mouse(gameDirector);
    //position the mouse and attach a picture
    mouse->setPos(mouse->getPos());
    mouse->setPixmap(QPixmap("Images/mouse.jpg").scaled(mouse->getWidth(),mouse->getHeight(),
                                                        Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    _gameScene->addItem(mouse);

}

void StandardGameSceneBuilder::buildSnake(GameDirector* gameDirector){

    if(dynamic_cast<Scene*>(_gameScene)->isItemPresentInScene<Snake>()) return;


    Snake* snake = new Snake(gameDirector);
    snake->setPos(const_initial_head_snake_x,const_initial_head_snake_x);
    snake->setPixmap(QPixmap("Images/snakehead.png").scaled(const_step_move,const_step_move,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    snake->setFlag(QGraphicsItem::ItemIsFocusable);
    snake->setFocus();

    _gameScene->addItem(snake);
}



QGraphicsScene* StandardGameSceneBuilder::getScene(){

    return _gameScene;
}
