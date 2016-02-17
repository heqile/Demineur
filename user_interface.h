#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <QObject>
#include <QtCore>
#include <QtWidgets>
#include "blockarea.h"

class user_interface : public QMainWindow
{
    Q_OBJECT
public:
    explicit user_interface(QWidget *parent = 0);

private:
    QAction *mAction;
    QMenu *mMenu;
    QToolBar *mToolBar;
    QStatusBar *mStatusBar;

    BlockArea *mBlockArea;

signals:

public slots:
    void mRestart( );
};

#endif // USER_INTERFACE_H
