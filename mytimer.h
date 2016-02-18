#ifndef MYTIMER_H
#define MYTIMER_H

#include <QObject>
#include <QtCore>
#include <QtWidgets>

class MyTimer : public QTimer
{
    Q_OBJECT
public:
    explicit MyTimer(QWidget *parent = 0);

signals:


public slots:
};

#endif // MYTIMER_H
