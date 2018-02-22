#include "gamedirector.h"

//game director built as a singleton
GameDirector* GameDirector::_gameDirector = nullptr;

GameDirector::GameDirector(){}

//static member used to retrieve the director instance
GameDirector* GameDirector::getInstance(){
      if(!_gameDirector)
          return _gameDirector = new GameDirector;

      return _gameDirector;
}

//observer pattern used to update scene items following specific events
//attach each game object to the observer list
void GameDirector::attachGameObject(GameObject* gameObject){
         _listGameObjects.push_back(gameObject);
}

//game objects update following notification of mouse hit
void GameDirector::notifyMouseSwallow(QGraphicsItem* bit){

    for(auto it = _listGameObjects.begin(); it!=_listGameObjects.end(); it++){
              (*it)->update(bit);
    }

}

//game over notification
//game exit or game objects reset depending on player's choice
void GameDirector::notifyGameOver(){

    int response = QMessageBox::question(nullptr, "Game Over", "Would you like to restart?", QMessageBox::Yes | QMessageBox::No);

    if (response == QMessageBox::Yes){
                 for(auto it = _listGameObjects.begin(); it!=_listGameObjects.end(); it++)
                          (*it)->reset();
                  QCoreApplication::instance()->exit(const_reboot);
     }
     else if (response == QMessageBox::No){
                  QCoreApplication::instance()->exit(0);
     }
}

