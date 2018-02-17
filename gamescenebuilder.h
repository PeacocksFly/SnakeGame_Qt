#ifndef GAMESCENEBUILDER_H
#define GAMESCENEBUILDER_H

#include <QGraphicsView>

class GameSceneBuilder{

public:
    GameSceneBuilder() = default;

    virtual void buildScene() = 0;
    virtual void buildView() = 0;
    virtual void buildScore() = 0;
    virtual void buildMouse() = 0;
    virtual void buildSnake() = 0;

    virtual QGraphicsScene* getScene() = 0;

};


#endif // GAMESCENEBUILDER_H
