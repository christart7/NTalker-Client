#include <QtGui>
#include "myinfo.h"
#include <QtXml>
#include <QtScript>


MyInfo::MyInfo(QWidget *parent):QWidget(parent)
  {
    extern QString ID ;
    extern QString user;
    extern QString sID;

    manager = new QNetworkAccessManager(this);  //�½�QNetworkAccessManager����
    connect(manager,SIGNAL(finished(QNetworkReply*)),  //�����źźͲ�
                this,SLOT(getinforeplyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://59.64.156.229:8080/ntalker-lbs/queryUser.action;jsessionid="
                                      +sID+"?id="+ID+"&type=Symbian")));

    PhotoDisplay *myPic = new PhotoDisplay;
    myPic->setPixmap(QPixmap(":/image/my.jpg"));
    myName = new QLabel;
    myName->setText(user);

    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addWidget(myPic);
    topLayout->addWidget(myName);

//    info = new QLabel(tr("������Ϣ"));
//    info->setAlignment(Qt::AlignHCenter);
    QVBoxLayout *mainLayout = new QVBoxLayout();

    name = new QLabel(tr("�ǳ�"));
    nameEdit = new QLineEdit(tr("Mark"));
    sign = new QLabel(tr("ǩ��"));
    signEdit = new QTextEdit(tr("Nothing is as good as it seems beforehand."));
    school = new QLabel(tr("ѧУ"));
    schoolEdit = new QLineEdit(tr("BUPT"));
    interest = new QLabel(tr("��Ȥ"));
    interestEdit = new QTextEdit(tr("Program, Read, Swim"));
    QGridLayout *basicGrid= new QGridLayout;
    basicGrid->addWidget(name,0,0);
    basicGrid->addWidget(nameEdit,0,1);
    basicGrid->addWidget(sign,1,0);
    basicGrid->addWidget(signEdit,1,1);
    basicGrid->addWidget(school,2,0);
    basicGrid->addWidget(schoolEdit,2,1);
    basicGrid->addWidget(interest,3,0);
    basicGrid->addWidget(interestEdit,3,1);

    QGroupBox *basicinfoBox = new QGroupBox;
    basicinfoBox->setTitle(tr("������Ϣ"));
    basicinfoBox->setAlignment(Qt::AlignHCenter);
    basicinfoBox->setLayout(basicGrid);



//   QPushButton *moreinfoBtn = new QPushButton(tr("������Ϣ"));

//   birthday = new QLabel(tr("����"));
//   birthplace = new QLabel(tr("����"));
//   qq = new QLabel("QQ");
//   mobile = new Qlabel(tr("�ֻ�"));
//   bi


    mainLayout->addLayout(topLayout);
//    mainLayout->addWidget(info);
    mainLayout->addWidget(basicinfoBox);
    setLayout(mainLayout);



//    setLayout(mainLayout);

    connect(myPic,SIGNAL(clicked()),this,SLOT(getPic()));
//    connect(nameEdit,SIGNAL())

}

void MyInfo::getinforeplyFinished(QNetworkReply *reply){
    QTextCodec *codec = QTextCodec::codecForName("utf8");//ʹ��utf8���룬�����ſ�����ʾ����
    QString all = codec->toUnicode(reply->readAll());
    QScriptValue sc;
    QScriptEngine engine;
    sc = engine.evaluate("(" + all + ")");
    QScriptValueIterator it(sc);

    it.next();
    QScriptValue sce =  it.value();
    QScriptValueIterator ite(sce);
    ite.next();

    while (ite.hasNext()) {
//        if(ite.name() == "username"){
//            myName->setText(ite.value().toString());
//        }

        if(ite.name() == "realname"){
            nameEdit->setText(ite.value().toString());
        }
        if(ite.name() == "bio"){
            signEdit->setText(ite.value().toString().toUtf8());
            qDebug()<< ite.value().toString();;
        }
        ite.next();
        //           qDebug() <<ite.name() << ":" << ite.value().toString();
    }
}



void MyInfo::getPic(){
    PicDialog *p = new PicDialog(this);
    p->setFixedHeight(280);
    p->show();
}
PicDialog::PicDialog(QWidget *parent):QDialog(parent){
    setFont(QFont("",8,QFont::Normal));
    QPushButton *fromfile = new QPushButton(tr("���ļ�"));
    QPushButton *photo = new QPushButton(tr("����"));
    QPushButton *cancel = new QPushButton(tr("����"));
    QLabel *title = new QLabel(tr("�ϴ�ͷ��"));title->setAlignment(Qt::AlignCenter);
    title->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    QVBoxLayout *main = new QVBoxLayout;
    main->addWidget(title);
    main->addWidget(fromfile);
    main->addWidget(photo);
    main->addWidget(cancel);
    setLayout(main);

    connect(cancel,SIGNAL(clicked()),this,SLOT(deleteLater()));
}
void PhotoDisplay::mousePressEvent(QMouseEvent *e)
{
    if (e->x() != e->y())
        puts("x != y");
    emit clicked();
}



