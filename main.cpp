#include <QApplication>
#include "const_def.h"
#include "snakegame.h"
#include "standardgamescenebuilder.h"
#include "gamedirector.h"

int main(int argc, char *argv[])
{
    int reboot;
  //  do{
        GameDirector* gameDirector = GameDirector::getInstance();
        StandardGameSceneBuilder builder;
        QApplication *game = new SnakeGame(argc, argv, builder, gameDirector);

game->exec();
       // reboot = game->exec();
        //delete game;
   // }while(reboot == const_reboot);

    return reboot;
}
