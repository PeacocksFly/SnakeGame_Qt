#include "standardgamescenebuilder.h"

StandardGameSceneBuilder::StandardGameSceneBuilder():
    GameSceneBuilder(),
    _gameScene(nullptr){
}

void StandardGameSceneBuilder::buildScene(){

    if(_gameScene) return;

    _gameScene = new Scene;
    _gameScene->setSceneRect(0,0,const_length,const_width);
}

void StandardGameSceneBuilder::buildView(){

    if(!_gameScene->views().empty()) return;

    View* view = new View(_gameScene);

    view->setBackgroundBrush(Qt::green);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(const_length,const_width);
    view->show();
}


void StandardGameSceneBuilder::buildScore(){

    if(dynamic_cast<Scene*>(_gameScene)->isItemPresentInScene<Score>()) return;

    Score* score = new Score;
    //display snake score
    score->setPlainText("Mickeys: " + QString::number(score->getScore()));
    score->setDefaultTextColor(Qt::red);
    score->setFont(QFont("arial",20));
    _gameScene->addItem(score);
}

void StandardGameSceneBuilder::buildMouse(){

    if(dynamic_cast<Scene*>(_gameScene)->isItemPresentInScene<Mouse>()) return;

    Mouse* mouse = new Mouse;
    //position the mouse and attach a picture
    mouse->setPos(mouse->getPos());
    mouse->setPixmap(QPixmap("Images/mouse.jpg").scaled(mouse->getWidth(),mouse->getHeight(),
                                                        Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    _gameScene->addItem(mouse);

}

void StandardGameSceneBuilder::buildSnake(){


}



QGraphicsScene* StandardGameSceneBuilder::getScene(){

    return _gameScene;
}
