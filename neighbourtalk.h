#ifndef NEIGHBOURTALK_H
#define NEIGHBOURTALK_H

#include <QtGui>

class NeighbourTalk : public QWidget
{
    Q_OBJECT
public:
    NeighbourTalk(QWidget *parent=0);
private:
    QLabel *neighbourPic;
    QLabel *neighbourName;
    QLabel *vsLabel;
    QLabel *myName;
    QLabel *myPic;
    QHBoxLayout *topLayout;

    QLabel *infoLabel;
    QListWidget *list;
    QVBoxLayout *bottomLayout;
    QTextEdit *textEdit;
    QVBoxLayout *mainLayout;
private slots:
};

#endif // NEIGHBOURTALK_H
