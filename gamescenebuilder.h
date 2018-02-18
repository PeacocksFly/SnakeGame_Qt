#ifndef GAMESCENEBUILDER_H
#define GAMESCENEBUILDER_H

#include <QGraphicsView>
#include "gamedirector.h"

class GameSceneBuilder{

public:  

    virtual void buildScene(GameDirector*) = 0;
    virtual void buildView(GameDirector*) = 0;
    virtual void buildScore(GameDirector*) = 0;
    virtual void buildMouse(GameDirector*) = 0;
    virtual void buildSnake(GameDirector*) = 0;

    virtual QGraphicsScene* getScene() = 0;

protected:

    GameSceneBuilder() = default;
};


#endif // GAMESCENEBUILDER_H
