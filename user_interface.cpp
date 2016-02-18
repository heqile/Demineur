#include "user_interface.h"
#include <QtCore>
#include <QtWidgets>
#include "blockarea.h"

user_interface::user_interface(QWidget *parent) : QMainWindow(parent)
{
    mAction = new QAction(tr("&Restart"),this);
    mAction->setShortcut(QKeySequence::Refresh);

    mMenu = menuBar()->addMenu(tr("&Restart"));
    mMenu->addAction(mAction);

    mToolBar = addToolBar(tr("&Restart"));
    mToolBar->addAction(mAction);

    mStatusBar = statusBar();
    mStatusBar->showMessage("hi",3000);

    mBlockArea = new BlockArea(this);
    setCentralWidget(mBlockArea);
    mBlockArea->show();

    connect(mAction,SIGNAL(triggered(bool)),this,SLOT(mRestart()));
    connect(mBlockArea,SIGNAL(signalLose()),this,SLOT(onLose()));
}

void user_interface::mRestart()
{
  //  QMessageBox::information(this,"title","clicked");
     mBlockArea->close();
     mBlockArea = new BlockArea(this);
     setCentralWidget(mBlockArea);
     mBlockArea->show();
     connect(mBlockArea,SIGNAL(signalLose()),this,SLOT(onLose()));
     mStatusBar->showMessage("Start",3000);
}

void user_interface::onLose()
{
        mBlockArea->setEnabled(false);
}
