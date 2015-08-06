#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QtNetwork>

class MainWindow:public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
private:
    QTabWidget *tabWidget;

};
class LoginWindow : public QDialog{
    Q_OBJECT
public:
    LoginWindow(QWidget *parent = 0);

public slots:
     void toreg();
     void login();
     void replyFinished(QNetworkReply *);

private:
     QLineEdit *nameEdit;
     QLineEdit *pwEdit;
     QNetworkAccessManager *manager;


};
class RegisterWindow : public QDialog{
    Q_OBJECT
public:
    RegisterWindow(QWidget *parent = 0);
public slots:
    void reg();
    void replyFinished(QNetworkReply *);
private:
    QRadioButton *male;
    QRadioButton *female;
    QLineEdit *nameEdit;
    QLineEdit *mailEdit;
    QLineEdit *pwEdit;
    QLineEdit *repeatEdit;
    QNetworkAccessManager *manager;


};
class InfoDialog:public QDialog{
    Q_OBJECT
public:
    InfoDialog(QWidget *parent,QString string){
        QMessageBox  *msgbox = new QMessageBox;
        msgbox->addButton(tr("È·¶¨"), QMessageBox::AcceptRole);
        msgbox->setText(string);
        msgbox->exec();
    }

};

#endif // MAINWINDOW_H
