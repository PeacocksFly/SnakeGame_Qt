#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <typeinfo>
#include "gameobject.h"

class Scene: public QGraphicsScene{

public:
    Scene():QGraphicsScene() {}

   //check if a specific type of object exists in the scene
   template<typename T> int isItemPresentInScene();

};


template<typename T>
int Scene::isItemPresentInScene(){

   QList<QGraphicsItem*> listItems = items();

   for(auto it = listItems.begin(); it!= listItems.end(); it++)
       if (typeid(**it)  == typeid(T))
           return 1;
   return 0;
}


#endif // SCENE_H
