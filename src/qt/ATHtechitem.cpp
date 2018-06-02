#include "ATHtechitem.h"
#include "ui_ATHtechitem.h"

ATHtechitem::ATHtechitem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ATHtechitem),
    host(""),
    name("")
{
    ui->setupUi(this);
}

void ATHtechitem::setHost(QString hostStr)
{
    host = hostStr;
    ui->serverHostLabel->setText(hostStr);
}

void ATHtechitem::setName(QString nameStr)
{
    name = nameStr;
    ui->serverNameLabel->setText(nameStr);
}

ATHtechitem::~ATHtechitem()
{
    delete ui;
}
