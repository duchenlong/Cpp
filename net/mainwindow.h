#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "control.h"
#include "card.h"
#include "netpack.h"
#include <unistd.h>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void reshow(QString);
    void on_pushButton_2_clicked();

    bool check();                   // 判断输入网卡是否合理
    bool GetPack(int val = 0);      // 抓取数据包
    void on_pushButton_3_clicked();
    void on_progressBar_valueChanged(int value);

signals:
    void  signalSend(QString);      // 信号触发
private:
    Ui::MainWindow *ui;

private:
    card*        netC_window;
    netpack*     pack_window;
};
#endif // MAINWINDOW_H
