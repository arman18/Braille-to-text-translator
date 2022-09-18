#ifndef PASSWORD_H
#define PASSWORD_H

#include <QLineEdit>
#include<QKeyEvent>
class Password : public QLineEdit
{
public:
public:
    Password(QWidget *parent = nullptr);
    void checkPass();
    void keyPressEvent(QKeyEvent *e);
public:
    QString password = "myPass";
    int validity = 365;
};

#endif // PASSWORD_H
