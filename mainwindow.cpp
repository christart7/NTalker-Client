#include <QtGui>
#include <QtXml>

#include "mainwindow.h"
#include "grouptalk.h"
#include "neighbourtalk.h"
#include "friends.h"
#include "myinfo.h"


MainWindow::MainWindow()
{
    setWindowTitle(tr("聊天"));
    tabWidget = new QTabWidget;
    tabWidget->setFont(QFont("",8,QFont::Normal));
    //    tabWidget->setTabPosition(QTabWidget::South);
    setCentralWidget(tabWidget);
    tabWidget->setFixedSize(360,640);


    tabWidget->addTab(new GroupTalk, tr("群碰"));
    tabWidget->addTab(new NeighbourTalk, tr("单碰"));
    tabWidget->addTab(new Friends, tr("好友"));
    tabWidget->addTab(new MyInfo, tr("我"));
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);

}


LoginWindow::LoginWindow(QWidget *parent):QDialog(parent){
    setFont(QFont("",8,QFont::Normal));
    manager = new QNetworkAccessManager(this);  //新建QNetworkAccessManager对象
    connect(manager,SIGNAL(finished(QNetworkReply*)),  //关联信号和槽
            this,SLOT(replyFinished(QNetworkReply*)));

    QPushButton *exitBtn = new QPushButton(tr("退出"));
    exitBtn->setFixedWidth(70);
    QPushButton *test = new QPushButton("test");
    test->setFixedHeight(50);
    QLabel *title = new QLabel(tr("用户登录"));title->setFont(QFont("",10,QFont::Bold));
    QPushButton *registerBtn = new QPushButton(tr("注册"));
    registerBtn->setFixedWidth(70);
    title->setAlignment(Qt::AlignHCenter);
    setFont(QFont("",8,QFont::Normal));
    QLabel *name = new QLabel(tr("用户名"));
    QLabel  *password = new QLabel(tr("密码"));
    nameEdit = new QLineEdit;
    pwEdit = new QLineEdit;pwEdit->setEchoMode(QLineEdit::Password);
    QPushButton *login = new QPushButton(tr("登录"));
    login->setFixedHeight(50);

    QHBoxLayout *top = new QHBoxLayout;
    top->addWidget(exitBtn);
    top->addWidget(title);top->addWidget(registerBtn);

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(name,0,0);grid->addWidget(nameEdit,0,1);
    grid->setVerticalSpacing(30);
    grid->addWidget(password,1,0);grid->addWidget(pwEdit,1,1);

    QVBoxLayout *main = new QVBoxLayout;
    main->addSpacing(40);
    main->addLayout(top);
    main->addSpacing(30);
    main->addLayout(grid);
    main->addSpacing(40);
    main->addWidget(login);
    main->addSpacing(30);
    main->addWidget(test);
    main->addStretch();
    setLayout(main);

    nameEdit->setFocus();

    connect(login,SIGNAL(clicked()),this,SLOT(login()));
    connect(exitBtn,SIGNAL(clicked()),this,SLOT(close()));
    connect(registerBtn,SIGNAL(clicked()),this,SLOT(toreg()));
    connect(test,SIGNAL(clicked()),this,SLOT(accept())); ////测试所用
}

RegisterWindow::RegisterWindow(QWidget *parent):QDialog(parent){
    QLabel *title = new QLabel(tr("新用户注册"));title->setFont(QFont("",10,QFont::Bold));
    setFont(QFont("",8,QFont::Normal));
    title->setAlignment(Qt::AlignHCenter);
    QLabel *name = new QLabel(tr("用户名"));
    QLabel *mail = new QLabel(tr("邮箱"));
    QLabel *sex = new QLabel(tr("性别"));
    QLabel  *password = new QLabel(tr("密码"));
    QLabel  *repeat = new QLabel(tr("重复密码"));
    male =new QRadioButton(tr("男"));
    female =new QRadioButton(tr("女"));
    nameEdit = new QLineEdit;
    mailEdit = new QLineEdit;
    pwEdit = new QLineEdit;pwEdit->setEchoMode(QLineEdit::Password);
    repeatEdit = new QLineEdit;repeatEdit->setEchoMode(QLineEdit::Password);
    QPushButton *sub =new QPushButton(tr("提交"));
    sub->setFixedHeight(50);


    QGridLayout *grid = new QGridLayout;
    grid->addWidget(name,0,0);grid->addWidget(nameEdit,0,1,1,2);
    grid->addWidget(mail,1,0);grid->addWidget(mailEdit,1,1,1,2);
    grid->addWidget(sex,2,0);grid->addWidget(male,2,1);grid->addWidget(female,2,2);
    grid->addWidget(password,3,0);grid->addWidget(pwEdit,3,1,1,2);
    grid->addWidget(repeat,4,0);grid->addWidget(repeatEdit,4,1,1,2);
    grid->setVerticalSpacing(10);
    QPushButton *relogin = new QPushButton(tr("返回登录界面"));
    relogin->setFixedHeight(50);
    QVBoxLayout *main =new QVBoxLayout;
    main->addSpacing(40);
    main->addWidget(title);
    main->addSpacing(30);
    main->addLayout(grid);
    main->addSpacing(40);
    main->addWidget(sub);
    main->addSpacing(20);
    main->addWidget(relogin);
    main->addStretch();
    setLayout(main);

    connect(relogin,SIGNAL(clicked()),this,SLOT(deleteLater()));
    connect(sub,SIGNAL(clicked()),this,SLOT(reg()));
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),
            this,SLOT(replyFinished(QNetworkReply*)));

}


void LoginWindow::toreg(){
    RegisterWindow *m = new RegisterWindow;
    m->showFullScreen();
}

void LoginWindow::login(){
    if(nameEdit->text().isEmpty()||pwEdit->text().isEmpty()){
       InfoDialog(this,tr("用户名和密码不能为空，请重新输入"));
    }
    else manager->get(QNetworkRequest(QUrl("http://59.64.156.229:8080/ntalker-lbs/login.action?username="
                                           +nameEdit->text()+"&password="+pwEdit->text()+"&type=Symbian")));
}

void LoginWindow::replyFinished(QNetworkReply *reply)  //当回复结束后
{
    extern QString ID;extern QString user;extern QString sID;
    QString all =reply->readAll();
    QDomDocument doc;
    doc.setContent(all);
    QDomElement docElem = doc.documentElement();  //返回根元素
    QDomNode n = docElem.firstChild();
    while(!n.isNull())
    {

        if(n.toElement().text()=="Succeeded"){
            ID = n.nextSibling().toElement().text();
            user = n.nextSibling().nextSibling().toElement().text();
            sID = n.nextSibling().nextSibling().nextSibling().toElement().text();
            qDebug()<< ID<<user<<sID;
            accept();
        }
        if (n.toElement().text()=="Failed") {
            InfoDialog(this,tr("用户名或密码错误，请重新登录..."));
            nameEdit->clear();
            pwEdit->clear();
            nameEdit->setFocus();
        }
        n = n.nextSibling();
    }
    reply->deleteLater();
}


void RegisterWindow::reg(){
    if(nameEdit->text().isEmpty()||pwEdit->text().isEmpty()||mailEdit->text().isEmpty()
            ||repeatEdit->text().isEmpty()||!(male->isChecked()||female->isChecked())){
        InfoDialog(this,tr("所用信息都需填写，请重新输入"));
    }
    if(pwEdit->text()!=repeatEdit->text()){
        InfoDialog(this,tr("两次密码不一致，请重新输入"));
    }
    if(male->isChecked()){
        manager->get(QNetworkRequest(QUrl("http://59.64.156.229:8080/ntalker-lbs/register.action?username="+nameEdit->text()
                                          +"&email="+mailEdit->text()+"&password="
                                          +pwEdit->text()+"&gender=0&type=Symbian")));
           }

    if(female->isChecked()){
        manager->get(QNetworkRequest(QUrl("http://59.64.156.229:8080/ntalker-lbs/register.action?username="+nameEdit->text()
                                          +"&email="+mailEdit->text()+"&password="
                                          +pwEdit->text()+"&gender=1&type=Symbian")));
           }

}

void RegisterWindow::replyFinished(QNetworkReply *reply){
    extern QString ID;extern QString user;extern QString sID;
    QString all =reply->readAll();
    QDomDocument doc;
    doc.setContent(all);
    QDomElement docElem = doc.documentElement();  //返回根元素
    QDomNode n = docElem.firstChild();
    while(!n.isNull())
    {
        if(n.toElement().text()=="Succeeded"){
            ID = n.nextSibling().toElement().text();
            InfoDialog(this,tr("注册成功！"));
            qDebug()<< ID;

        }
        if (n.toElement().text()=="Failed") {
            InfoDialog(this,tr("注册失败，用户名或邮箱可能已被使用"));
            nameEdit->setFocus();
        }
        n = n.nextSibling();
    }
    reply->deleteLater();
}
