#include "gamedirector.h"


GameDirector* GameDirector::_gameDirector = nullptr;

GameDirector::GameDirector(){}

GameDirector* GameDirector::getInstance(){
      if(!_gameDirector)
          return _gameDirector = new GameDirector;

      return _gameDirector;
}

void GameDirector::attachGameObject(GameObject* gameObject){
         _listGameObjects.push_back(gameObject);
}


void GameDirector::notifyMouseSwallow(){

    for(auto it = _listGameObjects.begin(); it!=_listGameObjects.end(); it++)
             (*it)->update();

    //            scene->addItem(snake.front());    ///!!!
    //            mouse->mouse_position_generator(snake);   ///!!!
   //



}

