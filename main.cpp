//#include<QtPlugin>
//Q_IMPORT_PLUGIN(qsvg)
//Q_IMPORT_PLUGIN(qgif)
//Q_IMPORT_PLUGIN(qjpeg)
//Q_IMPORT_PLUGIN(qico)
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
    return a.exec();
}
