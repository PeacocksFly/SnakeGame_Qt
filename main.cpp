#include <QApplication>
#include "const_def.h"
#include "snakegame.h"
#include "standardgamescenebuilder.h"
#include "gamedirector.h"

int main(int argc, char *argv[])
{
    int reboot;
    StandardGameSceneBuilder builder;
    QApplication *snakeGame = new SnakeGame(argc, argv, builder);

    do{
        reboot = snakeGame->exec();
    }while(reboot == const_reboot);

    delete snakeGame;

    return 0;
}
