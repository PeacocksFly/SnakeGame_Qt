#ifndef GAMEDIRECTOR_H
#define GAMEDIRECTOR_H

class GameDirector{

public:
    static GameDirector* getInstance();

private:
    GameDirector();
    static GameDirector* _gameDirector;

}


#endif // GAMEDIRECTOR_H
