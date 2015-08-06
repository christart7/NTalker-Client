#ifndef MYINFO_H
#define MYINFO_H

#include <QtGui>
#include <QtNetwork>

class MyInfo :public QWidget
{
Q_OBJECT
public:
    MyInfo(QWidget *parent=0);
private:
    QLabel *myName;
    QLabel *info;
    QLabel *name;
    QLineEdit *nameEdit;
    QLabel *sign;
    QTextEdit *signEdit;
    QLabel *school;
    QLineEdit *schoolEdit;
    QLabel *interest;
    QTextEdit *interestEdit;

    QLabel *birthday;
    QLineEdit *birthdayEdit;
    QLabel *birthplace;
    QTextEdit *birthplaceEdit;
    QLabel *qq;
    QLineEdit *qqEdit;
    QLabel *mobile;
    QTextEdit *mobileEdit;

    QNetworkAccessManager *manager;

private slots:
      void getinforeplyFinished(QNetworkReply *);
//      void updatereplyFinished(QNetworkReply*);

      void getPic();
};
class PicDialog : public QDialog{
    Q_OBJECT
public:
    PicDialog(QWidget *parent = 0);
};
class PhotoDisplay : public QLabel // inherit QLabel
{
    Q_OBJECT

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *);
};


#endif // MYINFO_H
