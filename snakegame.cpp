#include "snakegame.h"

SnakeGame::SnakeGame(int argc, char *argv[], GameSceneBuilder& builder) :
    QApplication(argc, argv),
    _gameScene(nullptr)
{

    _gameScene = createGameScene(builder);

    //create, set and play music background object
    musicbg = new QMediaPlayer;
    musicbg->setMedia(QUrl::fromLocalFile("Music/musicbgg.wav"));
    musicbg->play();


    //create snake object (added to the scene
    //within snake constructor)
  //  snake = new Snake(scene, mouse, score);

}

QGraphicsScene* SnakeGame::createGameScene(GameSceneBuilder& builder){

    builder.buildScene();
    builder.buildView();
    builder.buildScore();
    builder.buildMouse();
    builder.buildSnake();

    return builder.getScene();
}



SnakeGame::~SnakeGame()
{
    //release memory
    delete snake;
  //  scene->removeItem(mouse);
  //  delete mouse;
    delete musicbg;
 //   delete score;
    delete view;
 //   delete scene;
}
