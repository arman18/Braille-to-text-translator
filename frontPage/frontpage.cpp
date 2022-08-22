#include "frontpage.h"
#include "ui_frontpage.h"
#include "startlabel.h"
#include <QDebug>
#include <QSizePolicy>
FrontPage::FrontPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FrontPage)
{
    ui->setupUi(this);
    setWindowTitle("Bangla Braille Converter");
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(ui->labelStart,&StartLabel::clicked,[=](){accept();});
}

FrontPage::~FrontPage()
{
    delete ui;
}

void FrontPage::closeEvent(QCloseEvent *)
{
    //qDebug()<<"what happened";
    QApplication::quit();
}

