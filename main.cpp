#include <QtGui>
#include "mainwindow.h"

extern QString ID = "0";
extern QString user = "Null";
extern QString sID = "Null";
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    LoginWindow l;
    l.showFullScreen();

    if(l.exec()==QDialog::Accepted)
    {
    MainWindow m;
    m.showFullScreen();
    return app.exec();
    }
    return 0;


}
