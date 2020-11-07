#ifndef TCP_H
#define TCP_H

#include <QWidget>
#include "control.h"

namespace Ui {
class tcp;
}

class tcp : public QWidget
{
    Q_OBJECT

public:
    explicit tcp(QWidget *parent = nullptr);
    ~tcp();
private:
    void parse();       // 解析 TCP协议 到界面
private:
    Ui::tcp *ui;
};

#endif // TCP_H
