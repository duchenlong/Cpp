#include "netpack.h"
#include "ui_netpack.h"

udp* udp_window = nullptr;     // udp协议窗口
tcp* tcp_window = nullptr;     // udp协议窗口

netpack::netpack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::netpack)
{
    ui->setupUi(this);
    QImage* image1 = new QImage();
    QPalette* palette = new  QPalette();
    image1->load("./1.jpg");
    palette->setBrush(this->backgroundRole(),QBrush(*image1));
    setPalette(*palette);

    setWindowTitle("以太网协议与ip协议");
    parse();
}

netpack::~netpack()
{
    delete ui;
    delete tcp_window;
    delete udp_window;
    tcp_window = nullptr;
    udp_window = nullptr;
}

void netpack::parse() {
#define FUN(A) QString::fromStdString(A)

    // 数据链路层 以太网帧头部
    ui->descMac->setPlaceholderText(FUN(::eth_protocal->_decs));
    ui->srcMac->setPlaceholderText(FUN(::eth_protocal->_src));
    ui->type->setPlaceholderText(FUN(::eth_protocal->_type));
    ui->data1->setPlaceholderText(FUN(::eth_protocal->_str));

    // 网络层 ip 协议
    ui->srcIp->setPlaceholderText(FUN(::ip_protocal->_src));
    ui->descip->setPlaceholderText(FUN(::ip_protocal->_desc));
    ui->version->setPlaceholderText(FUN(::ip_protocal->_version));
    ui->headLen->setPlaceholderText(FUN(::ip_protocal->_handerLen));
    ui->diffserv->setPlaceholderText(FUN(::ip_protocal->_diffserv));
    ui->totalLen->setPlaceholderText(FUN(::ip_protocal->_totalLen));
    ui->identification->setPlaceholderText(FUN(::ip_protocal->_identification));
    ui->flag_offset->setPlaceholderText(FUN(::ip_protocal->_flag_offset));
    ui->timeLive->setPlaceholderText(FUN(::ip_protocal->_timeLive));
    ui->protocal->setPlaceholderText(FUN(::ip_protocal->_protocol));
    ui->checkSum->setPlaceholderText(FUN(::ip_protocal->_checkSum));
    ui->data2->setPlaceholderText(FUN(::ip_protocal->_str[0]));
    ui->data3->setPlaceholderText(FUN(::ip_protocal->_str[1]));
    ui->data4->setPlaceholderText(FUN(::ip_protocal->_str[2]));

    // 传输层 协议名称
    ui->transport->setPlaceholderText(FUN(GetTranPro()));
}

void netpack::on_pushButton_clicked()
{
    switch (atoi((::ip_protocal)->_protocol.c_str())) {
    case 1: break;
    case 6:     tcp_window = new tcp();tcp_window->show();break;
    case 17:    udp_window = new udp();udp_window->show();break;
    }
}
