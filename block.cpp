#include "block.h"
#include <QtCore>
#include <QtWidgets>

Block::Block(bool mine_flag, QWidget* parent):QLabel(parent)
{
    mine_flag_ = mine_flag;
    ok_flag_   = false;
    mark_flag_ = false;
    number_    = -1;
    setPixmap(QPixmap(":/image/normal"));
}

void Block::setNumber(int number)
{
    number_ = number;
}

bool Block::isMine()const
{
    return mine_flag_;
}

void Block::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(ok_flag_ || mark_flag_);
        else
        {
            ok_flag_ = true;
            if(mine_flag_)
            {
                setPixmap(QPixmap(":/image/mineBoom"));
                update();
                emit signalExplore();
            }
            else
            {
/*                switch(number_)
                {
                    case 0: setPixmap(QPixmap(":/image/0"));break;
                    case 1: setPixmap(QPixmap(":/image/1"));break;
                    case 2: setPixmap(QPixmap(":/image/2"));break;
                    case 3: setPixmap(QPixmap(":/image/3"));break;
                    case 4: setPixmap(QPixmap(":/image/4"));break;
                }*/

//                setPixmap(QPixmap(":/image/"+QString("%1").arg(number_)));
                setPixmap(QPixmap(":/image/"+QString::number(number_)));
                update();

                //QString::number(number_)
                emit signalSafe();
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
