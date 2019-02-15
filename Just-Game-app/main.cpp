#include "widget.h"
#include "gameform.h"
#include "rest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    rest_api::get_gamenames();

    Widget w;
    w.show();

    return a.exec();
}
