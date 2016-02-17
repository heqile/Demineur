#ifndef BLOCKAREA_H
#define BLOCKAREA_H

#include <QWidget>
#include <QtCore>
#include <QtWidgets>
#include "block.h"

class BlockArea: public QWidget
{
    Q_OBJECT
public:
    BlockArea(QWidget* parent=0);
private slots:
    void slotExplore();
    void slotSafe(int x, int y);
//    void slotSafe_zero();
private:
    QGridLayout *layout;
    int column_;
    int row_;
    int total_block_number_;
    int total_mine_number_;
    int total_ok_block_number;
private:
    int calculateMine(int x,int y)const;
    int openBlockArea(int x, int y,int* count)const;


};

#endif // BLOCKAREA_H
