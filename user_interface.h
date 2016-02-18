#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <QObject>
#include <QtCore>
#include <QtWidgets>
#include "blockarea.h"
#include "mytimer.h"

class user_interface : public QMainWindow
{
    Q_OBJECT
public:
    explicit user_interface(QWidget *parent = 0);

private:
    QAction *Rest_;
    QMenu *mMenu;
    QToolBar *mToolBar;
    QStatusBar *mStatusBar;
    MyTimer *mTimer;
    BlockArea *mBlockArea;
    QLabel *time_label;
    void mStart();
    int timer_;

signals:

public slots:
    void mRestart();
    void onLose();
    void onWin();
    void count_time();

};

#endif // USER_INTERFACE_H
