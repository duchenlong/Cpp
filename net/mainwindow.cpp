#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("网络抓包小程序");
    setWindowIcon(QIcon(":/images/design.ico"));        //图标

    // 背景图片
    QImage* image1 = new QImage();
    QPalette* palette = new  QPalette();
    image1->load("./1.jpg");
    palette->setBrush(this->backgroundRole(),QBrush(*image1));
    setPalette(*palette);

    this->netC_window = new card();
    connect(netC_window,&card::signalSend, \
            this,&MainWindow::reshow);

    this->pack_window = nullptr;
}

// 网卡信息
void MainWindow::on_pushButton_5_clicked()
{
    netC_window->show();
    this->hide();
}

void MainWindow::reshow(QString y) {
    this->show();
    ui->idx->setText(y);
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
}

#define WARNWIND(ERR)     QMessageBox::warning(NULL, "有点问题", ERR, QMessageBox::Yes, QMessageBox::Yes)

bool MainWindow::check() {
    // 网卡信息不可以为空
    if(ui->idx->text() == "") {
        WARNWIND("input network card not empty");
        return false;
    }
    int idx = ui->idx->text().toInt();      // 获得输入网卡编号
    if(idx <= 0 || idx > ::size) {          // 判断是否合理
        WARNWIND("network card idx error");
        return false;
    }

    bool ret = setSniffing(idx-1);            // 对指定网卡建立嗅探
    if(!ret) {
        WARNWIND("network card open error");
        return false;
    }

    return true;
}

// 随机抓包
void MainWindow::on_pushButton_clicked()
{
    bool ret = check();
    if(ret == false) return ;

    ret = GetPack(0);       // 0 随机抓包
    if(ret == false) return ;

// cout << "now" << endl;
    // 写入包信息到界面
    pack_window = new netpack();
    pack_window->show();
}



// tcp pack
void MainWindow::on_pushButton_2_clicked()
{
    bool ret = check();
    if(ret == false) return ;

    ret = GetPack(1);       // 1 TCP数据包
    if(ret == false) return ;

    // 写入包信息到界面
    pack_window = new netpack();
    pack_window->show();
}

// UDP pack
void MainWindow::on_pushButton_3_clicked()
{
    bool ret = check();
    if(ret == false) return ;

    ret = GetPack(2);       // 2 UDP数据包
    if(ret == false) return ;

    // 写入包信息到界面
    pack_window = new netpack();
    pack_window->show();
}

// 抓取数据包
bool MainWindow::GetPack(int val) {
    bool ret = false;

    this->on_progressBar_valueChanged(0);
    for(int i = 0; i < 10; i++) {
        this->on_progressBar_valueChanged((i + 1) * 10);
        ret = Parse(val);
        if(ret == true) {
            this->on_progressBar_valueChanged(100);
            usleep(90000);
            break;
        }
    }
    this->on_progressBar_valueChanged(0);
    if(!ret) {
        WARNWIND("network package parse error");
        return false;
    }
    return true;
}

void MainWindow::on_progressBar_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}
