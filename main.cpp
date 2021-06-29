#include "Maplibrary_form\maplibrary.h"

#include <QApplication>
#include<direct.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    -mkdir(".\\data");
    maplibrary w;
    w.show();
    return a.exec();
}
/*
 "Phone number : 09015743537"
 "Telegram ID : @Mat-Mot"
 "Instgram ID : matin_motmaen"
 "Git repo : https://github.com/mat-mot/ap-final-project.git"
 "Email addres : matinmotmaen@gmail.com"
 "this program wrriten by mat-mot (*_*)"
 "for AP final project"
 "finished alpha version in 2021/06/28 "
 "finished gama version in 2021/06/29 "
*/
