#include "mainwindow.h"
#include <QApplication>
#include <init.h>
#include <mypcap.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    initFront(a);   // 设置中文字体

    // 初始化网卡信息
    bool ret = infoNetwork();
    if(ret == false) return 1;


    MainWindow* main_window = new MainWindow();
    main_window->show();

    return a.exec();
}
