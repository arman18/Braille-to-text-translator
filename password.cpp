#include "password.h"
#include <QLineEdit>
#include <QScreen>
#include <QApplication>
#include <QSettings>
#include <QDate>
Password::Password(QWidget *parent):QLineEdit(parent)
{
    setWindowFlags(Qt::Dialog | Qt::Desktop);

    int width = QGuiApplication::screens()[0]->size().width();
    int height = QGuiApplication::screens()[0]->size().height();
    setWindowTitle("Input Password");
    move(QPoint(width/2-45,height/3));
    setWindowModality(Qt::WindowModal);
    setEchoMode(QLineEdit::Password);

}

void Password::checkPass()
{
    QString pass;
    int day;
    QSettings setting("mySoft","braille");
    setting.beginGroup("passworrd");
        pass = setting.value("pass","no").toString();
        day = setting.value("pass_date",QDate::currentDate()).toDate().toJulianDay();
        setting.endGroup();
        if(pass==password) {
//            qDebug()<<QDate::currentDate().toJulianDay()-day;
                if(QDate::currentDate().toJulianDay()-day<validity)
            return;
        }
        show();


}

void Password::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == 16777220){

        QString input = text();
        if(input==password){
            QSettings setting("mySoft","braille");
                setting.beginGroup("passworrd");
                setting.setValue("pass",input);
                setting.setValue("pass_date",QDate::currentDate());
                setting.endGroup();
            close();
        }
        else {
            setWindowTitle("Invalid Password");
            setText("");
        }
    }

    return QLineEdit::keyPressEvent(e);
}
