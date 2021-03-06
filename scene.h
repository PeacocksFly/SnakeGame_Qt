#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <typeinfo>
#include "gameobject.h"

class Scene: public QGraphicsScene, public GameObject{

public:
    Scene(GameDirector* gameDirector):
        QGraphicsScene(),
        GameObject(gameDirector){
              gameDirector->attachGameObject(this);
    }

   //attach a new snake bit to the scene when snake grows
   virtual void update(QGraphicsItem* bit){
              addItem(bit);
    }

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
