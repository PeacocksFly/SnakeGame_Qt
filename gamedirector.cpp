#include "gamedirector.h"


GameDirector* GameDirector::_gameDirector = nullptr;

GameDirector::GameDirector(){}

GameDirector* GameDirector::getInstance(){
      if(!_gameDirector)
          return _gameDirector = new GameDirector;

      return _gameDirector;
}
