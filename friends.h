#ifndef FRIENDS_H
#define FRIENDS_H

#include <QtGui>

class Friends :public QWidget
{
Q_OBJECT
public:
    Friends(QWidget *parent=0);
private slots:
    void getFriendsInfo();

};

#endif // FRIENDS_H
