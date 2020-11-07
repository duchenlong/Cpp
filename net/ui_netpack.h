/********************************************************************************
** Form generated from reading UI file 'netpack.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETPACK_H
#define UI_NETPACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_netpack
{
public:
    QLabel *label_2;
    QLineEdit *descMac;
    QLineEdit *srcMac;
    QLineEdit *type;
    QLabel *label_4;
    QLineEdit *headLen;
    QLineEdit *srcIp;
    QLineEdit *identification;
    QLineEdit *version;
    QLineEdit *diffserv;
    QLineEdit *totalLen;
    QLineEdit *flag_offset;
    QLineEdit *timeLive;
    QLineEdit *protocal;
    QLineEdit *checkSum;
    QLineEdit *descip;
    QLabel *label_5;
    QPushButton *pushButton;
    QLineEdit *transport;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *data1;
    QLineEdit *data2;
    QLineEdit *data3;
    QLineEdit *data4;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;

    void setupUi(QWidget *netpack)
    {
        if (netpack->objectName().isEmpty())
            netpack->setObjectName(QStringLiteral("netpack"));
        netpack->resize(1243, 630);
        label_2 = new QLabel(netpack);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 0, 161, 51));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        descMac = new QLineEdit(netpack);
        descMac->setObjectName(QStringLiteral("descMac"));
        descMac->setGeometry(QRect(50, 80, 251, 41));
        QFont font1;
        font1.setPointSize(14);
        descMac->setFont(font1);
        descMac->setFocusPolicy(Qt::NoFocus);
        descMac->setAlignment(Qt::AlignCenter);
        descMac->setReadOnly(true);
        srcMac = new QLineEdit(netpack);
        srcMac->setObjectName(QStringLiteral("srcMac"));
        srcMac->setGeometry(QRect(300, 80, 261, 41));
        srcMac->setFont(font1);
        srcMac->setFocusPolicy(Qt::NoFocus);
        srcMac->setAlignment(Qt::AlignCenter);
        srcMac->setReadOnly(true);
        type = new QLineEdit(netpack);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(560, 80, 131, 41));
        type->setFont(font1);
        type->setFocusPolicy(Qt::NoFocus);
        type->setAlignment(Qt::AlignCenter);
        type->setReadOnly(true);
        label_4 = new QLabel(netpack);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(310, 130, 111, 51));
        label_4->setFont(font);
        headLen = new QLineEdit(netpack);
        headLen->setObjectName(QStringLiteral("headLen"));
        headLen->setGeometry(QRect(150, 230, 81, 41));
        headLen->setFont(font1);
        headLen->setFocusPolicy(Qt::NoFocus);
        headLen->setAlignment(Qt::AlignCenter);
        headLen->setReadOnly(true);
        srcIp = new QLineEdit(netpack);
        srcIp->setObjectName(QStringLiteral("srcIp"));
        srcIp->setGeometry(QRect(70, 490, 621, 41));
        srcIp->setFont(font1);
        srcIp->setFocusPolicy(Qt::NoFocus);
        srcIp->setAlignment(Qt::AlignCenter);
        srcIp->setReadOnly(true);
        identification = new QLineEdit(netpack);
        identification->setObjectName(QStringLiteral("identification"));
        identification->setGeometry(QRect(70, 330, 311, 41));
        identification->setFont(font1);
        identification->setFocusPolicy(Qt::NoFocus);
        identification->setAlignment(Qt::AlignCenter);
        identification->setReadOnly(true);
        version = new QLineEdit(netpack);
        version->setObjectName(QStringLiteral("version"));
        version->setGeometry(QRect(70, 230, 81, 41));
        version->setFont(font1);
        version->setFocusPolicy(Qt::NoFocus);
        version->setAlignment(Qt::AlignCenter);
        version->setReadOnly(true);
        diffserv = new QLineEdit(netpack);
        diffserv->setObjectName(QStringLiteral("diffserv"));
        diffserv->setGeometry(QRect(230, 230, 151, 41));
        diffserv->setFont(font1);
        diffserv->setFocusPolicy(Qt::NoFocus);
        diffserv->setAlignment(Qt::AlignCenter);
        diffserv->setReadOnly(true);
        totalLen = new QLineEdit(netpack);
        totalLen->setObjectName(QStringLiteral("totalLen"));
        totalLen->setGeometry(QRect(380, 230, 311, 41));
        totalLen->setFont(font1);
        totalLen->setFocusPolicy(Qt::NoFocus);
        totalLen->setAlignment(Qt::AlignCenter);
        totalLen->setReadOnly(true);
        flag_offset = new QLineEdit(netpack);
        flag_offset->setObjectName(QStringLiteral("flag_offset"));
        flag_offset->setGeometry(QRect(380, 330, 311, 41));
        flag_offset->setFont(font1);
        flag_offset->setFocusPolicy(Qt::NoFocus);
        flag_offset->setAlignment(Qt::AlignCenter);
        flag_offset->setReadOnly(true);
        timeLive = new QLineEdit(netpack);
        timeLive->setObjectName(QStringLiteral("timeLive"));
        timeLive->setGeometry(QRect(70, 410, 151, 41));
        timeLive->setFont(font1);
        timeLive->setFocusPolicy(Qt::NoFocus);
        timeLive->setAlignment(Qt::AlignCenter);
        timeLive->setReadOnly(true);
        protocal = new QLineEdit(netpack);
        protocal->setObjectName(QStringLiteral("protocal"));
        protocal->setGeometry(QRect(220, 410, 161, 41));
        protocal->setFont(font1);
        protocal->setFocusPolicy(Qt::NoFocus);
        protocal->setAlignment(Qt::AlignCenter);
        protocal->setReadOnly(true);
        checkSum = new QLineEdit(netpack);
        checkSum->setObjectName(QStringLiteral("checkSum"));
        checkSum->setGeometry(QRect(380, 410, 311, 41));
        checkSum->setFont(font1);
        checkSum->setFocusPolicy(Qt::NoFocus);
        checkSum->setAlignment(Qt::AlignCenter);
        checkSum->setReadOnly(true);
        descip = new QLineEdit(netpack);
        descip->setObjectName(QStringLiteral("descip"));
        descip->setGeometry(QRect(70, 570, 621, 41));
        descip->setFont(font1);
        descip->setFocusPolicy(Qt::NoFocus);
        descip->setAlignment(Qt::AlignCenter);
        descip->setReadOnly(true);
        label_5 = new QLabel(netpack);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(760, 490, 271, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei"));
        font2.setPointSize(14);
        label_5->setFont(font2);
        pushButton = new QPushButton(netpack);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(950, 560, 261, 61));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QLatin1String("QPushButton { background-color:rgb(0, 255, 127); border:2px solid #014F84; color: rgb(rgb(0, 0, 0)); }\n"
"QPushButton:hover { background-color: rgb(200, 194, 181); }"));
        transport = new QLineEdit(netpack);
        transport->setObjectName(QStringLiteral("transport"));
        transport->setGeometry(QRect(1040, 470, 121, 71));
        transport->setFont(font1);
        transport->setFocusPolicy(Qt::NoFocus);
        transport->setAlignment(Qt::AlignCenter);
        transport->setReadOnly(true);
        label = new QLabel(netpack);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 190, 41, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setMargin(0);
        label_3 = new QLabel(netpack);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 190, 81, 31));
        label_3->setFont(font3);
        label_3->setMargin(0);
        label_6 = new QLabel(netpack);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(270, 190, 81, 31));
        label_6->setFont(font3);
        label_6->setMargin(0);
        label_7 = new QLabel(netpack);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(510, 190, 81, 31));
        label_7->setFont(font3);
        label_7->setMargin(0);
        label_8 = new QLabel(netpack);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(100, 290, 261, 31));
        label_8->setFont(font3);
        label_8->setMargin(0);
        label_9 = new QLabel(netpack);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(460, 280, 81, 31));
        label_9->setFont(font3);
        label_9->setMargin(0);
        label_10 = new QLabel(netpack);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(460, 300, 81, 31));
        label_10->setFont(font3);
        label_10->setMargin(0);
        label_11 = new QLabel(netpack);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(570, 290, 81, 31));
        label_11->setFont(font3);
        label_11->setMargin(0);
        label_12 = new QLabel(netpack);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(80, 380, 151, 31));
        label_12->setFont(font3);
        label_12->setMargin(0);
        label_13 = new QLabel(netpack);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(260, 380, 91, 31));
        label_13->setFont(font3);
        label_13->setMargin(0);
        label_14 = new QLabel(netpack);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(490, 380, 91, 31));
        label_14->setFont(font3);
        label_14->setMargin(0);
        label_15 = new QLabel(netpack);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(350, 460, 91, 31));
        label_15->setFont(font3);
        label_15->setMargin(0);
        label_16 = new QLabel(netpack);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(340, 540, 91, 31));
        label_16->setFont(font3);
        label_16->setMargin(0);
        label_17 = new QLabel(netpack);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(130, 40, 131, 31));
        label_17->setFont(font3);
        label_17->setMargin(0);
        label_18 = new QLabel(netpack);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(390, 40, 111, 31));
        label_18->setFont(font3);
        label_18->setMargin(0);
        label_19 = new QLabel(netpack);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(600, 40, 81, 31));
        label_19->setFont(font3);
        label_19->setMargin(0);
        data1 = new QLineEdit(netpack);
        data1->setObjectName(QStringLiteral("data1"));
        data1->setGeometry(QRect(720, 80, 511, 41));
        data1->setFont(font1);
        data1->setFocusPolicy(Qt::NoFocus);
        data1->setAlignment(Qt::AlignCenter);
        data1->setReadOnly(true);
        data2 = new QLineEdit(netpack);
        data2->setObjectName(QStringLiteral("data2"));
        data2->setGeometry(QRect(720, 230, 511, 41));
        data2->setFont(font1);
        data2->setFocusPolicy(Qt::NoFocus);
        data2->setAlignment(Qt::AlignCenter);
        data2->setReadOnly(true);
        data3 = new QLineEdit(netpack);
        data3->setObjectName(QStringLiteral("data3"));
        data3->setGeometry(QRect(720, 330, 511, 41));
        data3->setFont(font1);
        data3->setFocusPolicy(Qt::NoFocus);
        data3->setAlignment(Qt::AlignCenter);
        data3->setReadOnly(true);
        data4 = new QLineEdit(netpack);
        data4->setObjectName(QStringLiteral("data4"));
        data4->setGeometry(QRect(720, 410, 511, 41));
        data4->setFont(font1);
        data4->setFocusPolicy(Qt::NoFocus);
        data4->setAlignment(Qt::AlignCenter);
        data4->setReadOnly(true);
        label_20 = new QLabel(netpack);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(920, 40, 111, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Microsoft YaHei"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        label_20->setFont(font4);
        label_21 = new QLabel(netpack);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(920, 190, 111, 41));
        label_21->setFont(font4);
        label_22 = new QLabel(netpack);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(920, 290, 111, 41));
        label_22->setFont(font4);
        label_23 = new QLabel(netpack);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(920, 370, 111, 41));
        label_23->setFont(font4);

        retranslateUi(netpack);

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(netpack);
    } // setupUi

    void retranslateUi(QWidget *netpack)
    {
        netpack->setWindowTitle(QApplication::translate("netpack", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("netpack", "\346\225\260\346\215\256\351\223\276\350\267\257\345\261\202", Q_NULLPTR));
        descMac->setText(QString());
        label_4->setText(QApplication::translate("netpack", " \347\275\221\347\273\234\345\261\202", Q_NULLPTR));
        headLen->setText(QString());
        srcIp->setText(QString());
        identification->setText(QString());
        version->setText(QString());
        diffserv->setText(QString());
        totalLen->setText(QString());
        flag_offset->setText(QString());
        timeLive->setText(QString());
        protocal->setText(QString());
        checkSum->setText(QString());
        descip->setText(QString());
        label_5->setText(QApplication::translate("netpack", "\344\274\240\350\276\223\345\261\202\346\225\260\346\215\256\345\214\205\345\215\217\350\256\256\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("netpack", "\350\247\243\346\236\220", Q_NULLPTR));
        transport->setText(QString());
        label->setText(QApplication::translate("netpack", "\347\211\210\346\234\254", Q_NULLPTR));
        label_3->setText(QApplication::translate("netpack", "\351\246\226\351\203\250\351\225\277\345\272\246", Q_NULLPTR));
        label_6->setText(QApplication::translate("netpack", "\346\234\215\345\212\241\347\261\273\345\236\213", Q_NULLPTR));
        label_7->setText(QApplication::translate("netpack", "\346\200\273\351\225\277\345\272\246", Q_NULLPTR));
        label_8->setText(QApplication::translate("netpack", "\345\210\206\346\256\265\346\240\207\350\257\206(\346\240\207\350\257\206\345\261\236\344\272\216\345\220\214\344\270\200\346\225\260\346\215\256\346\212\245)", Q_NULLPTR));
        label_9->setText(QApplication::translate("netpack", "\346\234\252 D M", Q_NULLPTR));
        label_10->setText(QApplication::translate("netpack", "\347\224\250 F  F", Q_NULLPTR));
        label_11->setText(QApplication::translate("netpack", "\346\256\265\345\201\217\347\247\273", Q_NULLPTR));
        label_12->setText(QApplication::translate("netpack", "\347\224\237\345\255\230\345\221\250\346\234\237TTL(\347\247\222)", Q_NULLPTR));
        label_13->setText(QApplication::translate("netpack", "\344\270\212\345\261\202\345\215\217\350\256\256", Q_NULLPTR));
        label_14->setText(QApplication::translate("netpack", "\346\212\245\345\244\264\346\240\241\351\252\214\345\222\214", Q_NULLPTR));
        label_15->setText(QApplication::translate("netpack", "\346\272\220IP\345\234\260\345\235\200", Q_NULLPTR));
        label_16->setText(QApplication::translate("netpack", "\347\233\256\347\232\204IP\345\234\260\345\235\200", Q_NULLPTR));
        label_17->setText(QApplication::translate("netpack", "\347\233\256\347\232\204MAC\345\234\260\345\235\200", Q_NULLPTR));
        label_18->setText(QApplication::translate("netpack", "\346\272\220MAC\345\234\260\345\235\200", Q_NULLPTR));
        label_19->setText(QApplication::translate("netpack", "\351\225\277\345\272\246", Q_NULLPTR));
        label_20->setText(QApplication::translate("netpack", "\346\272\220\346\225\260\346\215\256", Q_NULLPTR));
        label_21->setText(QApplication::translate("netpack", "\346\272\220\346\225\260\346\215\256", Q_NULLPTR));
        label_22->setText(QApplication::translate("netpack", "\346\272\220\346\225\260\346\215\256", Q_NULLPTR));
        label_23->setText(QApplication::translate("netpack", "\346\272\220\346\225\260\346\215\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class netpack: public Ui_netpack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETPACK_H
