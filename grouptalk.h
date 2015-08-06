#ifndef GROUPTALK_H
#define GROUPTALK_H

#include <QtGui>
class GroupTalk :public QWidget
{
Q_OBJECT
public:
    GroupTalk(QWidget *parent=0);
private slots:
       void getInfo();
       void showTopicDialog();

};


#endif // GROUPTALK_H
