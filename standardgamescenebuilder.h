#ifndef STANDARDGAMESCENEBUILDER_H
#define STANDARDGAMESCENEBUILDER_H

#include "gamescenebuilder.h"
#include "const_def.h"
#include "scene.h"
#include "view.h"
#include "score.h"
#include "mouse.h"



class StandardGameSceneBuilder : public GameSceneBuilder{

public:
    StandardGameSceneBuilder();

    virtual void buildScene();
    virtual void buildView();
    virtual void buildScore();
    virtual void buildMouse();
    virtual void buildSnake();

    virtual QGraphicsScene* getScene();

private:
    QGraphicsScene* _gameScene;

};


#endif // STANDARDGAMESCENEBUILDER_H
