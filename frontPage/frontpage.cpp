#include "frontpage.h"
#include "ui_frontpage.h"
#include "startlabel.h"
#include <QDebug>

FrontPage::FrontPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FrontPage)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Bangla Braille Converter");
//    QCoreApplication::setAttribute(Qt::AA_DisableWindowContextHelpButton);
//    QCoreApplication::setAttribute();
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

