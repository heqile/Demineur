#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QtCore>
#include <QtWidgets>

class Block:public QLabel
{
    Q_OBJECT
public:
    explicit Block(bool mine_flag, QWidget* parent = 0);
public:
    void setNumber(int number);
    bool isMine() const;

private:
    bool ok_flag_;
    bool mark_flag_;
    bool mine_flag_;
    int  number_;
signals:
    void signalExplore();
    void signalSafe();
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // BLOCK_H
