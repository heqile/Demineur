#include "dialog.h"
#include <QApplication>
#include "blockarea.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Dialog w;
//    w.show();
    BlockArea w;
    w.show();
    return a.exec();
}
