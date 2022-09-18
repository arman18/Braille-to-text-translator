#include "mainwindow.h"

#include <Password.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile File(":/style/stylesheet.css");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    qApp->setStyleSheet(StyleSheet);
    MainWindow w;
    if(w.showFrontPage())
        w.show();
    else return 0;
    w.show();
    Password *pass = new Password(&w);
    pass->checkPass();
    return a.exec();
}
