#include "netcard.h"
#include "ui_netcard.h"
#include "mypcap.h"

netCard::netCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::netCard)
{
    ui->setupUi(this);
    infoNetwork();
    //ui->textEdit->setText(netcard);
}

netCard::~netCard()
{
    delete ui;
}
