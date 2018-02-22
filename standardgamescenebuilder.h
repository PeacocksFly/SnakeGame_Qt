#ifndef STANDARDGAMESCENEBUILDER_H
#define STANDARDGAMESCENEBUILDER_H

#include "gamescenebuilder.h"
#include "const_def.h"
#include "scene.h"
#include "view.h"
#include "score.h"
#include "mouse.h"
#include "snake.h"

class StandardGameSceneBuilder : public GameSceneBuilder{

public:
    StandardGameSceneBuilder();
    virtual void buildScene(GameDirector*);
    virtual void buildView();
    virtual void buildScore(GameDirector*);
    virtual void buildMouse(GameDirector*);
    virtual void buildSnake(GameDirector*);
    virtual QGraphicsScene* getScene();

private:
    QGraphicsScene* _gameScene;

};


#endif // STANDARDGAMESCENEBUILDER_H
