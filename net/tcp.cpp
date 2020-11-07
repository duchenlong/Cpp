#include "tcp.h"
#include "ui_tcp.h"

tcp::tcp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tcp)
{
    ui->setupUi(this);
    QImage* image1 = new QImage();
    QPalette* palette = new  QPalette();
    image1->load("./1.jpg");
    palette->setBrush(this->backgroundRole(),QBrush(*image1));
    setPalette(*palette);
    setWindowTitle("TCP 协议");
    parse();
}

tcp::~tcp()
{
    delete ui;
}

void tcp::parse() {
#define FUN(A) QString::fromStdString(A)
    ui->sport->setPlaceholderText(FUN(::tcp_protocal->_sport));
    ui->dport->setPlaceholderText(FUN(::tcp_protocal->_dport));
    ui->seqNum->setPlaceholderText(FUN(::tcp_protocal->_seqNum));
    ui->ackNum->setPlaceholderText(FUN(::tcp_protocal->_ackNum));
    ui->off_res_flag->setPlaceholderText(FUN(::tcp_protocal->_off_res_flag));
    ui->winSize->setPlaceholderText(FUN(::tcp_protocal->_winSize));
    ui->checkSum->setPlaceholderText(FUN(::tcp_protocal->_checkSum));
    ui->urgentPoint->setPlaceholderText(FUN(::tcp_protocal->_urgentPoint));

    ui->data1->setPlaceholderText(FUN(::tcp_protocal->_str[0]));
    ui->data2->setPlaceholderText(FUN(::tcp_protocal->_str[1]));
    ui->data3->setPlaceholderText(FUN(::tcp_protocal->_str[2]));
    ui->data4->setPlaceholderText(FUN(::tcp_protocal->_str[3]));
    ui->data5->setPlaceholderText(FUN(::tcp_protocal->_str[4]));
}
