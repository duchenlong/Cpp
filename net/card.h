#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include <QTableWidgetItem>
#include <string>
#include "control.h"
#include <QStandardItemModel>
#include <QDebug>
#include <QObject>

namespace Ui {
class card;
}

class card : public QWidget
{
    Q_OBJECT

public:
    QString buf;
    explicit card(QWidget *parent = nullptr);
    ~card();
    std::string GetId();
private slots:
    void on_table_itemDoubleClicked(QTableWidgetItem *item);

    void on_closeButton_clicked();

signals:
    void  signalSend(QString);      // 信号带参函数
private:
    Ui::card *ui;
    int     _idx;       // 选择网卡编号
};

#endif // CARD_H
