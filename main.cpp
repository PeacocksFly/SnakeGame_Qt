#include <QApplication>
#include "Const_Def.h"
#include "Game.h"

int main(int argc, char *argv[])
{
    int reboot;
    do{
        QApplication *game = new Game(argc, argv);
        reboot = game->exec();
        delete game;
    }while(reboot == const_reboot);

    return reboot;
}
