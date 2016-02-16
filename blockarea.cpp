#include "blockarea.h"
#include "block.h"

BlockArea::BlockArea(QWidget* parent):QWidget(parent)
{
    column_ = 10;
    row_ = 10;
    total_block_number_ = column_*row_;
    total_mine_number_ = 10;
    total_ok_block_number = 0;

    bool mine_flag[total_block_number_];
    for(int i = 0; i < total_mine_number_; i++)
        mine_flag[i] = true;
    for(int i = total_mine_number_; i < total_block_number_;i++)
        mine_flag[i] = false;
    std::random_shuffle(mine_flag,mine_flag+total_block_number_);

    layout = new QGridLayout(this);
    for(int i = 0; i < row_; i ++)
        for(int j = 0; j < column_; j++)
            layout->addWidget(new Block(mine_flag[i*row_+j]),i,j);

    for(int i = 0; i < row_; i ++)
        for(int j = 0; j < column_; j ++)
        {
            Block* current_block = static_cast<Block*>(layout->itemAtPosition(i,j)->widget());
            current_block->setNumber(calculateMine(i,j));
            connect(current_block,SIGNAL(signalSafe()),this,SLOT(slotSafe()));
            connect(current_block,SIGNAL(signalExplore()),this,SLOT(slotExplore()));
        }
    setFixedSize(sizeHint());
}

int BlockArea::calculateMine(int x, int y)const
{
    int num = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            if((x-1+i >= 0) && (x-1+i < row_) && (y-1+j >= 0) && (y-1+j < column_))
                if(static_cast<Block*>(layout->itemAtPosition(x-1+i,y-1+j)->widget())->isMine())
                    num++;
        }
    return num;
}

void BlockArea::slotExplore()
{
    QMessageBox::information(this,"reslut","You failed!");

}

void BlockArea::slotSafe()
{
    ++total_ok_block_number;
    if(total_ok_block_number == total_block_number_-total_mine_number_)
        QMessageBox::information(this,"result","Win!");
}
