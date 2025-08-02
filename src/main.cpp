#include "View/mainwindow.h"
#include "Engine/sensorlist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/Asset/icons/Museum.svg"));
    Engine::SensorList* mem = new Engine::SensorList();
    View::MainWindow window(mem);
    window.resize(1024, 600);
    window.show();
    return a.exec();
}
