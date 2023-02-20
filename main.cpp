#include "mainwindow.hpp"
#include <DApplication>


int main(int argc, char *argv[])
{
    DApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
