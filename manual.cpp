#include "manual.h"
#include "ui_manual.h"

Manual::Manual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manual)
{
    ui->setupUi(this);
}

Manual::~Manual()
{
    delete ui;
}
