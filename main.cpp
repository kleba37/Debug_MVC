#include "window.h"
#include <QApplication>
#include <Model.h>
#include <View.h>
#include <controller.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;

    Model * model           = new Model(new QRect(0,0, 50,50));
    View * view             = new View();
    Controller *controller  = new Controller();

    view->setModel(model);
    controller->setModel(model);
    controller->setView(view);

    w.setView(view);
    w.setController(controller);
    w.show();
    return a.exec();
}
