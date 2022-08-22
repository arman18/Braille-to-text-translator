#include "mainwindow.h"

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
    return a.exec();
}
