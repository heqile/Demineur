#include "dialog.h"
#include <QApplication>
#include "blockarea.h"
#include "user_interface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Dialog w;
//    w.show();
    user_interface w;
    w.show();
    return a.exec();
}
