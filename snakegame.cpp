#include "snakegame.h"

SnakeGame::SnakeGame(int argc, char *argv[], GameSceneBuilder& builder) :
    QApplication(argc, argv),
    _gameScene(nullptr){

    GameDirector* gameDirector = GameDirector::getInstance();
    _gameScene = createGameScene(builder, gameDirector);

    //create, set and play music background object
    musicbg = new QMediaPlayer;
    musicbg->setMedia(QUrl::fromLocalFile("Music/musicbgg.wav"));
    musicbg->play();
}

QGraphicsScene* SnakeGame::createGameScene(GameSceneBuilder& builder, GameDirector* gameDirector){
    //use of a builder pattern to set up the scene
    builder.buildScene(gameDirector);
    builder.buildView();
    builder.buildScore(gameDirector);
    builder.buildMouse(gameDirector);
    builder.buildSnake(gameDirector);

    return builder.getScene();
}



SnakeGame::~SnakeGame()
{

    if(_gameScene){
         QList<QGraphicsItem*> listItems = _gameScene->items();
         for(auto it = listItems.begin(); it!=listItems.end(); it++){
             _gameScene->removeItem(*it);
             delete *it;
         }

         QList<QGraphicsView*> listViews = _gameScene->views();
         for(auto it = listViews.begin(); it!=listViews.end(); it++){
             delete *it;
         }
    }

    delete musicbg;
}



