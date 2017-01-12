#include "dialog.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap("HS.jpg");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    Dialog w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
