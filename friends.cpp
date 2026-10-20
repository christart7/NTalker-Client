#include <QtGui>
#include"more.h"
#include "friends.h"


Friends::Friends(QWidget *parent):QWidget(parent)
{
    setFont(QFont("",6, QFont::Normal));
    QLabel *label=new QLabel;  //初始化qlabel
    QPixmap p1 (":/image/my") ;    //设定要显示的图片
    label->setPixmap(p1);  //将图片加载到label上
    label->setFixedSize(80,80);


    QLabel *labe1l = new QLabel(tr("GREEN"),this);

    QLabel *label2 = new QLabel(tr("<h6>You know that there's ...</h6>"),this);
    QPushButton *b = new QPushButton(">",this);
    QPushButton *b1 = new QPushButton(tr("私聊"));
    b1->setFixedSize(60,30);
    b1->setFixedWidth(80);


    QVBoxLayout * v = new QVBoxLayout;
    v->addWidget(labe1l);
    v->addWidget(label2);



    QHBoxLayout * h = new QHBoxLayout;

    h->addWidget(label);
    h->addLayout(v);
    h->addWidget(b);

    QWidget *w1=new QWidget;
    w1->setLayout(h);w1->setFixedHeight(100);
    QListWidget *list =new QListWidget;
    QListWidgetItem *item1 = new QListWidgetItem;
    list->addItem(item1);
    list->setItemWidget(item1,w1);
    item1->setSizeHint(QSize(sizeHint().width(),100));
    QVBoxLayout *wori=new QVBoxLayout;
    wori->addWidget(list);

    QGroupBox *box =new QGroupBox(tr("好友列表"),this);
    box->setLayout(wori);
    box->setFlat(1);
    //    box->setFixedWidth(360);



    QLabel *label3 =new QLabel(this);
    label3->setPixmap(p1);  //将图片加载到label上
    label3->setFixedSize(80,80);
    QLabel *label4=new QLabel(tr("<h4>Green</h4>"),this);
    QGroupBox *box1=new QGroupBox(tr("聊天"),this);

    QHBoxLayout * h1 = new QHBoxLayout;

    h1->addWidget(label3);
    h1->addWidget(label4);
    h1->addWidget(b1);
    box1->setFixedWidth(360);
    box1->setLayout(h1);

    QVBoxLayout * v1 = new QVBoxLayout;
    v1->addWidget(box);
    v1->addWidget(box1);
    setLayout(v1);



    connect(b,SIGNAL(clicked()),this,SLOT(getFriendsInfo()));

}
void Friends::getFriendsInfo(){
    FriendsInfo *dialog =new FriendsInfo;

    dialog->showFullScreen();
}

