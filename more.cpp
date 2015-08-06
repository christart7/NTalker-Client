#include<QtGui>
#include"more.h"
//#include"map.h"




FriendsInfo::FriendsInfo(QWidget *parent):QDialog(parent){

    setFont(QFont("",6, QFont::Normal));
    QLabel *myPic = new QLabel;
    myPic->setPixmap(QPixmap(":/image/my.jpg"));
    QLabel *myName = new QLabel;
    myName->setText("<h2>Mark</h2>");

    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(myPic);
    topLayout->addWidget(myName);

    QLabel *info = new QLabel(tr("������Ϣ"));
    info->setAlignment(Qt::AlignHCenter);
    QVBoxLayout *mainLayout = new QVBoxLayout();

    QLabel *name = new QLabel(tr("�ǳ�"));
    QLineEdit *nameText = new  QLineEdit(tr("Mark"));nameText->setReadOnly(1);
    QLabel *sign = new QLabel(tr("ǩ����"));
    QTextEdit *signText = new QTextEdit(tr("Nothing is as good as it seems beforehand.")); signText->setReadOnly(1);
    QLabel *school = new QLabel(tr("ѧУ"));
    QLineEdit *schoolText = new QLineEdit(tr("BUPT"));schoolText->setReadOnly(1);
    QLabel *interest = new QLabel(tr("��Ȥ"));
    QTextEdit *interestText = new QTextEdit(tr("Program, Read, Swim"));interestText->setReadOnly(1);
    QGridLayout *gLay= new QGridLayout;
    gLay->addWidget(name,0,0);
    gLay->addWidget(nameText,0,1);
    gLay->addWidget(sign,1,0);
    gLay->addWidget(signText,1,1);
    gLay->addWidget(school,2,0);
    gLay->addWidget(schoolText,2,1);
    gLay->addWidget(interest,3,0);
    gLay->addWidget(interestText,3,1);


    mainLayout->addWidget(info);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(gLay);
    setLayout(mainLayout);

    QAction *action=new QAction(QObject::tr("ȷ��"),this);
    action->setSoftKeyRole(QAction::NegativeSoftKey);
    this->addAction(action);
    connect(action,SIGNAL(triggered(bool)),
            this,SLOT(close()));

}
UnknownInfo::UnknownInfo(QWidget *parent):QDialog(parent){

    QLabel *title =new QLabel(tr("<h3>�ھ���Ϣ</h3>"));
    title->setAlignment(Qt::AlignHCenter);
    QLabel *pic = new QLabel;
    pic->setPixmap(QPixmap(":/image/button"));
    QLabel *name = new QLabel;
    name->setText("<h2>White</h2>");
    name->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    QLabel *address = new QLabel(tr("�����ʵ��ѧ"));
    QLabel *distance = new QLabel(tr("����"));
    QLineEdit *distanceText = new QLineEdit;
    distanceText->setText((tr("С��500��")));distanceText->setReadOnly(1);
    QLabel *sign = new QLabel(tr("ǩ��"));
    QTextEdit *signText = new QTextEdit(tr("Nothing is as good as it seems beforehand."));
    signText->setFixedHeight(120);signText->setReadOnly(1);

    QLabel *interest = new QLabel(tr("��Ȥ"));
    QTextEdit *interestText = new QTextEdit(tr("Program, Read, Swim"));
    interestText->setFixedHeight(60);interestText->setReadOnly(1);

    QGridLayout *top = new QGridLayout;
    top->addWidget(pic,0,0,2,1);top->addWidget(name,0,1);top->addWidget(address,1,1);

    QGridLayout *grid= new QGridLayout;
    grid->addWidget(distance,0,0);
    grid->addWidget(distanceText,0,1);
    grid->addWidget(sign,1,0);
    grid->addWidget(signText,1,1);
    grid->addWidget(interest,2,0);
    grid->addWidget(interestText,2,1);



    QAction *act1 = new QAction(tr("��Ϊ����"),this);
    act1->setSoftKeyRole(QAction::PositiveSoftKey);
    this->addAction(act1);
    QAction *act2=new QAction(QObject::tr("ȷ��"),this);
    act2->setSoftKeyRole(QAction::NegativeSoftKey);
    this->addAction(act2);

    QVBoxLayout *v =new QVBoxLayout;
    v->addWidget(title);
    v->addLayout(top);
    v->addLayout(grid);
    setLayout(v);
        connect(act1,SIGNAL(triggered(bool)),
                qApp,SLOT(aboutQt()));
    connect(act2,SIGNAL(triggered(bool)),
            this,SLOT(close()));
}
TopicDialog::TopicDialog(QWidget *parent):QDialog(parent){
    QTabWidget  *topicTab = new QTabWidget(this);
    topicTab->setFixedSize(360,640);
    topicTab->setFont(QFont("Times", 8, QFont::Normal));
    topicTab->addTab(new TopicList, tr("�б�"));
    topicTab->addTab(new Map, tr("��ͼ"));

    QAction *act1 = new QAction(tr("����"),this);
    act1->setSoftKeyRole(QAction::PositiveSoftKey);
    this->addAction(act1);
    QAction *act2=new QAction(QObject::tr("����"),this);
    act2->setSoftKeyRole(QAction::NegativeSoftKey);
    this->addAction(act2);

    connect(act1,SIGNAL(triggered(bool)),
            qApp,SLOT(aboutQt()));
    connect(act2,SIGNAL(triggered(bool)),
            this,SLOT(close()));

}

Map::Map(QWidget *parent):QDialog(parent){
    setFont(QFont("",6, QFont::Normal));
//    QLabel *LI =new QLabel(tr("�i�ಽ���"),this);


}
TopicList::TopicList(QWidget *parent):QDialog(parent){
    setFont(QFont("",6, QFont::Normal));
//    QLabel *YU =new QLabel(tr("�������Ь"),this);
}

