#ifndef SNAKE_H
#define SNAKE_H

#include "snakebit.h"
#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QRectF>
#include <deque>
#include <QGraphicsScene>
#include <memory>
#include <QMessageBox>
#include <QApplication>
#include <QProcess>
#include "mouse.h"
#include "score.h"
#include <QMediaPlayer>
#include"const_def.h"
#include <QSharedPointer>

class Snake : public QObject
{
    Q_OBJECT

public:
    Snake(QGraphicsScene *scene = nullptr, Mouse *mouse = nullptr, Score *score = nullptr);
    ~Snake();    
    void one_step_move(const qreal& x, const qreal& y, const Qt::Key& movestatus);

private:
    QGraphicsScene* scene;
    Mouse* mouse;
    Score* score;
    QTimer* timer;
    std::deque<SnakeBit*> snake;
    QMediaPlayer *hitmouse;

public slots:
    void move();

};
#endif // SNAKE_H
