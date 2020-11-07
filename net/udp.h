#ifndef UDP_H
#define UDP_H

#include <QWidget>
#include "control.h"

namespace Ui {
class udp;
}

class udp : public QWidget
{
    Q_OBJECT

public:
    explicit udp(QWidget *parent = nullptr);
    ~udp();
private:
    void parse();       // 解析到界面

private:
    Ui::udp *ui;
};

#endif // UDP_H
