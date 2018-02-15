#include "Game.h"

Game::Game(int argc, char *argv[]) : QApplication(argc, argv)
{

    //create, set and play music background object
    musicbg = new QMediaPlayer;
    musicbg->setMedia(QUrl::fromLocalFile("Music/musicbgg.wav"));
    musicbg->play();

    //create scene and set the dimensions
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,const_length,const_width);

    //create view, add a color, remove scrollbar
    //and set the dimensions
    view = new QGraphicsView(scene);
    view->setBackgroundBrush(Qt::green);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(const_length,const_width);
    view->show();
    //create mouse and add to the scene
    mouse = new Mouse();
    scene->addItem(mouse);

    //create score and add to the scene
    score = new Score();
    scene->addItem(score);

    //create snake object (added to the scene
    //within snake constructor)
    snake = new Snake(scene, mouse, score);

}

Game::~Game()
{
    //release memory
    delete snake;
    scene->removeItem(mouse);
    delete mouse;
    delete musicbg;
    delete score;
    delete view;
    delete scene;
}
