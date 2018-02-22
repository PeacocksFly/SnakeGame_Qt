#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QApplication>
#include <QMediaPlayer>
#include <QUrl>
#include <QImage>
#include <QBrush>
#include"const_def.h"
#include "gamescenebuilder.h"

class SnakeGame :  public QApplication{

public:
    SnakeGame(int argc, char *argv[], GameSceneBuilder&);
    ~SnakeGame();
    QGraphicsScene* createGameScene(GameSceneBuilder&,  GameDirector*);

private:
    QGraphicsScene* _gameScene;
    QMediaPlayer *musicbg;
};

#endif // GAME_H
