#include "user_interface.h"
#include <QtCore>
#include <QtWidgets>
#include "blockarea.h"
#include "mytimer.h"

user_interface::user_interface(QWidget *parent) : QMainWindow(parent)
{
    mTimer = new MyTimer(this);

    time_label = new QLabel(this);

    Rest_ = new QAction(tr("&Restart"),this);
    Rest_->setShortcut(QKeySequence::Refresh);

    mMenu = menuBar()->addMenu(tr("&Game"));
    mMenu->addAction(Rest_);
    mMenu = menuBar()->addMenu(tr("&Setting"));

    mToolBar = addToolBar(tr("&Restart"));
    mToolBar->addAction(Rest_);
    mToolBar->setMovable(false);

    mStatusBar = statusBar();
    mStatusBar->addPermanentWidget(time_label);

    mStart();
    connect(Rest_,SIGNAL(triggered(bool)),this,SLOT(mRestart()));
    connect(mTimer,SIGNAL(timeout()),this,SLOT(count_time()));

    setFixedSize(sizeHint());
}

void user_interface::mStart()
{

     mTimer->start(1000);
     timer_=0;
     mBlockArea = new BlockArea(this);
     setCentralWidget(mBlockArea);
     mBlockArea->show();
     connect(mBlockArea,SIGNAL(signalLose()),this,SLOT(onLose()));
     connect(mBlockArea,SIGNAL(signalWin()),this,SLOT(onWin()));
     time_label->setText("");
     mStatusBar->showMessage("Start",3000);
}

void user_interface::mRestart()
{
     mBlockArea->close();
     mStart();
}

void user_interface::onLose()
{

    mTimer->stop();
    mBlockArea->setEnabled(false);
    QMessageBox::information(this,"reslut","You lose!");
}

void user_interface::onWin()
{

    mTimer->stop();

    mBlockArea->setEnabled(false);
    QMessageBox::information(this,"result","Win!");
}

void user_interface::count_time()
{
    timer_++;
    time_label->setText(QString::number(timer_)+" second");

}
