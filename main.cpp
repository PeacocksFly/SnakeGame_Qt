#include <QApplication>
#include "const_def.h"
#include "snakegame.h"
#include "standardgamescenebuilder.h"

int main(int argc, char *argv[])
{
    int reboot;
  //  do{

        StandardGameSceneBuilder builder;
        QApplication *game = new SnakeGame(argc, argv, builder);

game->exec();
       // reboot = game->exec();
        //delete game;
   // }while(reboot == const_reboot);

    return reboot;
}
