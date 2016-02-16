#include "dialog.h"
#include "ui_dialog.h"
#include "blockarea.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    blockarea = new BlockArea(this);
//    blockarea->show();
}

Dialog::~Dialog()
{
    delete ui;
}
