#ifndef MORE_H
#define MORE_H
#include <QDialog>
#include <QtGui>


class FriendsInfo : public QDialog{
    Q_OBJECT
public:
    FriendsInfo(QWidget *parent = 0);

};
class UnknownInfo : public QDialog{
    Q_OBJECT
public:
    UnknownInfo(QWidget *parent = 0);
};

class TopicDialog : public QDialog{
    Q_OBJECT
public:
    TopicDialog(QWidget *parent = 0);

};
class Map :  public QDialog{
    Q_OBJECT
public:
    Map(QWidget *parent = 0);
 private:

};
class TopicList :  public QDialog{
    Q_OBJECT
public:
    TopicList(QWidget *parent = 0);

};


#endif // MORE_H
