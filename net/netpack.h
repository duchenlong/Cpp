#ifndef NETPACK_H
#define NETPACK_H

#include <QWidget>
#include "control.h"
#include "udp.h"
#include "tcp.h"

extern  udp* udp_window;     // udp协议窗口
extern  tcp* tcp_window;     // udp协议窗口

namespace Ui {
class netpack;
}

class netpack : public QWidget
{
    Q_OBJECT

public:
    explicit netpack(QWidget *parent = nullptr);
    ~netpack();
private slots:
    void on_pushButton_clicked();

private:
    void parse();       // 解析数据包，设置
private:
    Ui::netpack *ui;
};

#endif // NETPACK_H
