#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsRectItem>
#include "Snake.h"
#include "Mouse.h"
#include <vector>
#include <memory>
#include <QMediaPlayer>
#include <QUrl>
#include <QImage>
#include <QBrush>
#include "Score.h"
#include"Const_Def.h"

class Game :  public QApplication
{
public:
    Game(int argc, char *argv[]);
    ~Game();
private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    Mouse *mouse;
    Snake *snake;
    QMediaPlayer *musicbg;
    Score *score;
};

#endif // GAME_H
