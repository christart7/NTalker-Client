#include <QtGui>
#include "neighbourtalk.h"

NeighbourTalk::NeighbourTalk(QWidget *parent):QWidget(parent)
{
    neighbourPic = new QLabel();
    neighbourPic->setPixmap(QPixmap(":/image/neighbour.jpg"));
    neighbourName = new QLabel(tr("Mary"));
    vsLabel = new QLabel(tr("V.S."));
    myName = new QLabel(tr("Mark"));
    myPic = new QLabel();
    myPic->setPixmap(QPixmap(":/image/my.jpg"));

    topLayout = new QHBoxLayout;
    topLayout->addWidget(neighbourPic);
    topLayout->addWidget(neighbourName);
    topLayout->addWidget(vsLabel);
    topLayout->addWidget(myName);
    topLayout->addWidget(myPic);

    infoLabel = new QLabel();
    infoLabel->setText(tr("You Will Speck to a neighbour:"));

    list = new QListWidget();


    QLabel *pm2 = new QLabel();
    pm2->setPixmap(QPixmap(":/image/my.jpg"));
    QGroupBox *wig = new QGroupBox;
    QLabel *name = new QLabel(tr("Mark"));
    QLabel *time = new QLabel(tr("14:14"));
    QTextEdit *text = new QTextEdit();
    text->setText(tr("Hello!"));
    text->setReadOnly(true);
    QHBoxLayout *v1 = new QHBoxLayout;
    v1->addWidget(name);
    v1->addWidget(time);
    QVBoxLayout *v2 = new QVBoxLayout;
    v2->addLayout(v1);
    v2->addWidget(text);
    QHBoxLayout *v3 = new QHBoxLayout;
    v3->addWidget(pm2);
    v3->addLayout(v2);
    wig->setLayout(v3);

    QLabel *pm3 = new QLabel();
    pm3->setPixmap(QPixmap(":/image/neighbour.jpg"));
    QGroupBox *wig1 = new QGroupBox;
    QLabel *name1 = new QLabel(tr("Mary"));
    QLabel *time1 = new QLabel(tr("14:15"));
    QTextEdit *text1 = new QTextEdit();
    text1->setText(tr("Hello!"));
    text1->setReadOnly(true);
    QHBoxLayout *v4 = new QHBoxLayout;
    v4->addWidget(name1);
    v4->addWidget(time1);
    QVBoxLayout *v5 = new QVBoxLayout;
    v5->addLayout(v4);
    v5->addWidget(text1);
    QHBoxLayout *v6 = new QHBoxLayout;
    v6->addWidget(pm3);
    v6->addLayout(v5);
    wig1->setLayout(v6);

    textEdit = new QTextEdit();
    textEdit->setText(tr("hello!"));
    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(infoLabel);
    mainLayout->addWidget(wig);
    mainLayout->addWidget(wig1);
    mainLayout->addWidget(textEdit);
    setLayout(mainLayout);

}
