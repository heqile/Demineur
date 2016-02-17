#include "block.h"
#include "blockarea.h"
#include <QtCore>
#include <QtWidgets>

Block::Block(bool mine_flag, QWidget* parent):QLabel(parent)
{
    mine_flag_ = mine_flag;
    ok_flag_   = false;
    mark_flag_ = false;
    number_    = -1;
    num_column_= 0;
    num_row_   = 0;
    setPixmap(QPixmap(":/image/normal"));
}

void Block::setPosition(int x, int y)
{
    num_row_    = x;
    num_column_ = y;
}

void Block::setNumber(int number)
{
    number_ = number;
}

bool Block::isMine()const
{
    return mine_flag_;
}


int Block::openblock(int* count)
{

    if(ok_flag_ || mark_flag_);
    else
    {
        ok_flag_ = true;
        setPixmap(QPixmap(":/image/"+QString::number(number_)));
        update();
//        ++(*count);
        if(number_ == 0)
            return 1;
        else
            return 2;
    }
    return 0;
}


void Block::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(ok_flag_ || mark_flag_);
        else
        {

            if(mine_flag_)
            {
                ok_flag_ = true;
                setPixmap(QPixmap(":/image/mineBoom"));
                update();
                emit signalExplore();
            }
            else
            {
//                setPixmap(QPixmap(":/image/"+QString("%1").arg(number_)));
//                setPixmap(QPixmap(":/image/"+QString::number(number_)));
//                update();
//                openblock(this);
//                if(number_ == 0)
//               {
//                    emit signalSafe_zero(this);
//                }
//                else
//                {
                    emit signalSafe(num_row_,num_column_);
//                }

            }

        }
    }
    if(event->button() == Qt::RightButton)
    {
        if(!ok_flag_)
        {
            if(!mark_flag_)
            {
                setPixmap(QPixmap(":/image/mark"));
                mark_flag_ = true;
            }
            else
            {
                setPixmap(QPixmap(":/image/normal"));
                mark_flag_ = false;
            }
            update();
        }
    }
}
