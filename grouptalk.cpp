#include <QtGui>
#include "grouptalk.h"
#include "more.h"

GroupTalk::GroupTalk(QWidget *parent):QWidget(parent)
{
    QLabel *name1 = new QLabel(tr("<h4>Green</h4>"),this);
    QLabel *name2 = new QLabel(tr("<h4>White</h4>"),this);
    QLabel *name3 = new QLabel(tr("<h4>Mark</h4>"),this);

    QLabel *time1 = new QLabel;

    time1->setText(QTime::currentTime().toString("hh:mm"));
    time1->setFixedSize(60,30);

    QLabel * time2 = new QLabel(this);

    time2->setText("10:40");
    time2->setFixedSize(60,30);
    QLabel * time3 = new QLabel(this);

    time3->setText("12:15");
    time3->setFixedSize(60,30);



    QLabel *pic1=new QLabel;
    QImage image1;
    image1.load(":/image/button" );
    QPixmap pixmapToShow1 = QPixmap::fromImage( image1.scaled(80,80, Qt::KeepAspectRatio) );
    pic1->setPixmap(pixmapToShow1);

    QLabel *pic2=new QLabel;
    QImage image;
    image.load( ":/image/wood.jpg" );
    QPixmap pixmapToShow = QPixmap::fromImage( image.scaled(80,80, Qt::KeepAspectRatio) );
    pic2->setPixmap(pixmapToShow);//更好的加载图片的方法
    QLabel *pic3=new QLabel;
    QImage image2;
    image2.load( ":/image/my.jpg" );
    QPixmap pixmapToShow2 = QPixmap::fromImage( image2.scaled(80,80, Qt::KeepAspectRatio) );
    pic3->setPixmap(pixmapToShow2);//更好的加载图片的方法

    QLabel *word1 = new QLabel(tr("What's new now?"));
    QLabel *word2 = new QLabel;
    word2->setText(tr("Hello everyone!Hello everyone!"));
    QLabel *word3 = new QLabel(tr("hahahhahahahah"));
    word1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    word2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    word3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);

    QTextEdit *textline = new QTextEdit(tr("有什么要说的.."),this);
    textline->setFixedHeight(80);

    QGroupBox *pbox = new QGroupBox(tr("群聊"));
    pbox->setFixedSize(360,120);
    QListWidget *plist=new QListWidget(pbox);

    QListWidgetItem *pitem = new QListWidgetItem[7];


    pbox->setAlignment(Qt::AlignHCenter);
    QLabel *plabel = new QLabel[7];
    plabel[0].setPixmap(pixmapToShow);
    image.load( ":/image/button" );
    pixmapToShow = QPixmap::fromImage( image.scaled(80,80, Qt::KeepAspectRatio) );plabel[1].setPixmap(pixmapToShow);
    image.load( ":/image/my" );
    pixmapToShow = QPixmap::fromImage( image.scaled(80,80, Qt::KeepAspectRatio) );plabel[2].setPixmap(pixmapToShow);
    image.load( ":/image/neighbour" );
    pixmapToShow = QPixmap::fromImage( image.scaled(80,80, Qt::KeepAspectRatio) );plabel[3].setPixmap(pixmapToShow);
    image.load( ":/image/images1" );
    pixmapToShow = QPixmap::fromImage( image.scaled(80,80, Qt::KeepAspectRatio) );plabel[4].setPixmap(pixmapToShow);
    image.load( ":/image/images 2" );
    pixmapToShow = QPixmap::fromImage( image.scaled(80,80, Qt::KeepAspectRatio) );plabel[5].setPixmap(pixmapToShow);
    image.load( ":/image/images 3" );
    pixmapToShow = QPixmap::fromImage( image.scaled(80,80, Qt::KeepAspectRatio) );plabel[6].setPixmap(pixmapToShow);


    for(int i=0;i<7;i++){
        pitem[i].setSizeHint(QSize(70,70));
        plist->addItem(&pitem[i]);
        plist->setItemWidget(&pitem[i],&plabel[i]);
           }
    plist->setSpacing(5);
    plist->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    plist->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    plist->setFixedHeight(90);

    plist->setMovement(QListView::Static);
    plist->setFlow(QListView::LeftToRight);
//    plist->setViewMode(QListView::IconMode);

    QHBoxLayout * ha = new QHBoxLayout;
    ha->addWidget(name1);
    ha->addWidget(time2);


    QVBoxLayout * va = new QVBoxLayout;
    va->addLayout(ha);
    va->addWidget(word2);

    QHBoxLayout * hb = new QHBoxLayout;
    hb->addWidget(pic2);
    hb->addLayout(va);
    /////一个布局结束。。。。。

    QHBoxLayout * hbox = new QHBoxLayout;
    hbox->addWidget(name3);
    hbox->addWidget(time3);


    QVBoxLayout * vbox = new QVBoxLayout;
    vbox->addLayout(hbox);
    vbox->addWidget(word3);



    QHBoxLayout * lasthbox = new QHBoxLayout;
    lasthbox->addWidget(pic3);
    lasthbox->addLayout(vbox);

    QHBoxLayout * h = new QHBoxLayout;
    h->addWidget(name2);
    h->addWidget(time1);

    QVBoxLayout * v = new QVBoxLayout;
    v->addLayout(h);
    v->addWidget(word1);

    QHBoxLayout * h1 = new QHBoxLayout;
    h1->addWidget(pic1);
    h1->addLayout(v);

    QWidget *w1=new QWidget;
    QWidget *w2=new QWidget;
    QWidget *w3=new QWidget;
    w1->setLayout(hb);
    w2->setLayout(h1);
    w3->setLayout(lasthbox);
    QListWidget *list =new QListWidget;
    list->setFont(QFont("",7, QFont::Normal));
    list->setFrameStyle(QFrame::NoFrame);
    QListWidgetItem *item1 = new QListWidgetItem;
    QListWidgetItem *item2 = new QListWidgetItem;
    QListWidgetItem *item3 = new QListWidgetItem;
    list->addItem(item1);
    list->addItem(item2);
    list->addItem(item3);
    item1->setSizeHint(QSize(sizeHint().width(),100));
    item3->setSizeHint(QSize(sizeHint().width(),100));
    item2->setSizeHint(QSize(sizeHint().width(),100));


    list->setItemWidget(item1,w1);
    list->setItemWidget(item2,w2);
    list->setItemWidget(item3,w3);
//    list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    list->setFixedHeight(360);
//    list->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    // list->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

    QPushButton *input =new QPushButton(tr("输入"));
    input->setFixedSize(50,40);
    QHBoxLayout *low = new QHBoxLayout;
    low->addWidget(textline);low->addWidget(input);
    low->setAlignment(Qt::AlignBottom);
    QLabel *title = new QLabel(tr("群聊"));
    QPushButton *topicbutton =new QPushButton(tr("主题"));
    topicbutton->setFixedWidth(45);
    topicbutton->setFont(QFont("",8, QFont::Normal));
    QHBoxLayout *toph =new QHBoxLayout;
    toph->addSpacing(45); toph->addWidget(title);toph->addWidget(topicbutton);
    title->setAlignment(Qt::AlignHCenter);
    QVBoxLayout * tmain = new QVBoxLayout;
    tmain->addLayout(toph);
    tmain->addWidget(plist);
    tmain->addWidget(list);
    tmain->addLayout(low);

    setLayout(tmain);
    connect(plist,SIGNAL(clicked(QModelIndex)),
            this,SLOT(getInfo()));
    connect(topicbutton,SIGNAL(clicked()),this,SLOT(showTopicDialog()));

}
void GroupTalk::getInfo(){
    UnknownInfo *dialog=new  UnknownInfo;

      dialog->show();
}
void GroupTalk::showTopicDialog(){
    TopicDialog *dialog = new TopicDialog;
    dialog->showFullScreen();
}

