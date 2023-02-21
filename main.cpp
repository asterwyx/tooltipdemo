#include "mainwindow.hpp"
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    QDesktopWidget *desktop = QApplication::desktop();
    int currentScreen = desktop->screenNumber(&w);
    QRect rect = QGuiApplication::screens().at(currentScreen)->geometry();
    w.setGeometry(rect.width() / 2 - w.width() / 2, rect.height() /2 - w.height()/2, w.width(), w.height());
    w.setWindowIcon(QIcon::fromTheme("kbox"));
    w.resize(800, 600);
    w.show();
    return app.exec();
}
