#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QtCore>
#include <QtWidgets>
#include "blockarea.h"


class Block:public QLabel
{
    Q_OBJECT
public:
    explicit Block(bool mine_flag, QWidget* parent = 0);
public:
    void setNumber(int number);
    bool isMine() const;
    void setPosition(int x, int y);
    int openblock(int* count);
private:
    bool ok_flag_;
    bool mark_flag_;
    bool mine_flag_;
    int  number_;
    int  num_column_;
    int  num_row_;
signals:
    void signalExplore();
    void signalSafe(int x, int y);
//    void signalSafe_zero();
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // BLOCK_H
