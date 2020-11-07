#include <init.h>

void initFront(const QApplication& a) {
    //设置中文字体
    a.setFont(QFont("Microsoft Yahei", 9));
    //设置中文编码
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
}
