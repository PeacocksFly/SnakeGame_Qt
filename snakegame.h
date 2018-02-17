#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsRectItem>
#include "snake.h"
#include "mouse.h"
#include <vector>
#include <memory>
#include <QMediaPlayer>
#include <QUrl>
#include <QImage>
#include <QBrush>
#include "score.h"
#include"const_def.h"


#include "gamescenebuilder.h"
#include"gamedirector.h"

class SnakeGame :  public QApplication
{
public:
    SnakeGame(int argc, char *argv[], GameSceneBuilder&, GameDirector*);
    ~SnakeGame();
    QGraphicsScene* createGameScene(GameSceneBuilder& builder);

private:

    QGraphicsScene* _gameScene;


    QMediaPlayer *musicbg;

    QGraphicsView *view;


    Snake *snake;


};

#endif // GAME_H
