#include "udp.h"
#include "ui_udp.h"

udp::udp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::udp)
{
    ui->setupUi(this);
    QImage* image1 = new QImage();
    QPalette* palette = new  QPalette();
    image1->load("./1.jpg");
    palette->setBrush(this->backgroundRole(),QBrush(*image1));
    setPalette(*palette);
    setWindowTitle("UDP 协议");
    parse();
}

udp::~udp()
{
    delete ui;
}

// 解析到界面
void udp::parse() {
#define FUN(A) QString::fromStdString(A)
    ui->sport->setPlaceholderText(FUN(::udp_protocal->_sport));
    ui->dport->setPlaceholderText(FUN(::udp_protocal->_dport));
    ui->len->setPlaceholderText(FUN(::udp_protocal->_len));
    ui->lenW->setPlaceholderText(FUN(::udp_protocal->_len));
    ui->checkSum->setPlaceholderText(FUN(::udp_protocal->_checksum));

    ui->srcip->setPlaceholderText(FUN(::ip_protocal->_src));
    ui->descip->setPlaceholderText(FUN(::ip_protocal->_desc));

    ui->data1->setPlaceholderText(FUN(::udp_protocal->_str[0]));
    ui->data2->setPlaceholderText(FUN(::udp_protocal->_str[1]));
}
