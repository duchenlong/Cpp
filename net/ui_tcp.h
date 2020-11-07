/********************************************************************************
** Form generated from reading UI file 'tcp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCP_H
#define UI_TCP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tcp
{
public:
    QLabel *label;
    QLineEdit *sport;
    QLineEdit *dport;
    QLineEdit *seqNum;
    QLineEdit *ackNum;
    QLineEdit *off_res_flag;
    QLineEdit *winSize;
    QLineEdit *checkSum;
    QLineEdit *urgentPoint;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *data1;
    QLineEdit *data2;
    QLineEdit *data3;
    QLineEdit *data4;
    QLabel *label_14;
    QLineEdit *data5;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;

    void setupUi(QWidget *tcp)
    {
        if (tcp->objectName().isEmpty())
            tcp->setObjectName(QStringLiteral("tcp"));
        tcp->resize(1155, 658);
        label = new QLabel(tcp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(500, 0, 131, 71));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        sport = new QLineEdit(tcp);
        sport->setObjectName(QStringLiteral("sport"));
        sport->setGeometry(QRect(40, 100, 281, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        sport->setFont(font1);
        sport->setFocusPolicy(Qt::NoFocus);
        sport->setAlignment(Qt::AlignCenter);
        sport->setReadOnly(true);
        dport = new QLineEdit(tcp);
        dport->setObjectName(QStringLiteral("dport"));
        dport->setGeometry(QRect(320, 100, 281, 61));
        dport->setFont(font1);
        dport->setFocusPolicy(Qt::NoFocus);
        dport->setAlignment(Qt::AlignCenter);
        dport->setReadOnly(true);
        seqNum = new QLineEdit(tcp);
        seqNum->setObjectName(QStringLiteral("seqNum"));
        seqNum->setGeometry(QRect(40, 220, 561, 61));
        seqNum->setFont(font1);
        seqNum->setFocusPolicy(Qt::NoFocus);
        seqNum->setAlignment(Qt::AlignCenter);
        seqNum->setReadOnly(true);
        ackNum = new QLineEdit(tcp);
        ackNum->setObjectName(QStringLiteral("ackNum"));
        ackNum->setGeometry(QRect(40, 340, 561, 61));
        ackNum->setFont(font1);
        ackNum->setFocusPolicy(Qt::NoFocus);
        ackNum->setAlignment(Qt::AlignCenter);
        ackNum->setReadOnly(true);
        off_res_flag = new QLineEdit(tcp);
        off_res_flag->setObjectName(QStringLiteral("off_res_flag"));
        off_res_flag->setGeometry(QRect(40, 460, 281, 61));
        off_res_flag->setFont(font1);
        off_res_flag->setFocusPolicy(Qt::NoFocus);
        off_res_flag->setAlignment(Qt::AlignCenter);
        off_res_flag->setReadOnly(true);
        winSize = new QLineEdit(tcp);
        winSize->setObjectName(QStringLiteral("winSize"));
        winSize->setGeometry(QRect(320, 460, 281, 61));
        winSize->setFont(font1);
        winSize->setFocusPolicy(Qt::NoFocus);
        winSize->setAlignment(Qt::AlignCenter);
        winSize->setReadOnly(true);
        checkSum = new QLineEdit(tcp);
        checkSum->setObjectName(QStringLiteral("checkSum"));
        checkSum->setGeometry(QRect(40, 570, 281, 61));
        checkSum->setFont(font1);
        checkSum->setFocusPolicy(Qt::NoFocus);
        checkSum->setAlignment(Qt::AlignCenter);
        checkSum->setReadOnly(true);
        urgentPoint = new QLineEdit(tcp);
        urgentPoint->setObjectName(QStringLiteral("urgentPoint"));
        urgentPoint->setGeometry(QRect(320, 570, 281, 61));
        urgentPoint->setFont(font1);
        urgentPoint->setFocusPolicy(Qt::NoFocus);
        urgentPoint->setAlignment(Qt::AlignCenter);
        urgentPoint->setReadOnly(true);
        label_2 = new QLabel(tcp);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 60, 91, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_3 = new QLabel(tcp);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 60, 111, 41));
        label_3->setFont(font2);
        label_4 = new QLabel(tcp);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 170, 141, 41));
        label_4->setFont(font2);
        label_5 = new QLabel(tcp);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 300, 181, 41));
        label_5->setFont(font2);
        label_6 = new QLabel(tcp);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 420, 91, 41));
        label_6->setFont(font2);
        label_7 = new QLabel(tcp);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(140, 420, 61, 41));
        label_7->setFont(font2);
        label_8 = new QLabel(tcp);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(210, 390, 121, 41));
        label_8->setFont(font2);
        label_9 = new QLabel(tcp);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(210, 410, 121, 41));
        label_9->setFont(font2);
        label_10 = new QLabel(tcp);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(200, 430, 131, 41));
        label_10->setFont(font2);
        label_11 = new QLabel(tcp);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(420, 420, 91, 41));
        label_11->setFont(font2);
        label_12 = new QLabel(tcp);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(150, 530, 91, 41));
        label_12->setFont(font2);
        label_13 = new QLabel(tcp);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(430, 530, 91, 41));
        label_13->setFont(font2);
        data1 = new QLineEdit(tcp);
        data1->setObjectName(QStringLiteral("data1"));
        data1->setGeometry(QRect(640, 100, 491, 61));
        data1->setFont(font1);
        data1->setFocusPolicy(Qt::NoFocus);
        data1->setAlignment(Qt::AlignCenter);
        data1->setReadOnly(true);
        data2 = new QLineEdit(tcp);
        data2->setObjectName(QStringLiteral("data2"));
        data2->setGeometry(QRect(640, 220, 491, 61));
        data2->setFont(font1);
        data2->setFocusPolicy(Qt::NoFocus);
        data2->setAlignment(Qt::AlignCenter);
        data2->setReadOnly(true);
        data3 = new QLineEdit(tcp);
        data3->setObjectName(QStringLiteral("data3"));
        data3->setGeometry(QRect(640, 340, 491, 61));
        data3->setFont(font1);
        data3->setFocusPolicy(Qt::NoFocus);
        data3->setAlignment(Qt::AlignCenter);
        data3->setReadOnly(true);
        data4 = new QLineEdit(tcp);
        data4->setObjectName(QStringLiteral("data4"));
        data4->setGeometry(QRect(640, 460, 491, 61));
        data4->setFont(font1);
        data4->setFocusPolicy(Qt::NoFocus);
        data4->setAlignment(Qt::AlignCenter);
        data4->setReadOnly(true);
        label_14 = new QLabel(tcp);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(840, 60, 111, 41));
        label_14->setFont(font2);
        data5 = new QLineEdit(tcp);
        data5->setObjectName(QStringLiteral("data5"));
        data5->setGeometry(QRect(640, 570, 491, 61));
        data5->setFont(font1);
        data5->setFocusPolicy(Qt::NoFocus);
        data5->setAlignment(Qt::AlignCenter);
        data5->setReadOnly(true);
        label_15 = new QLabel(tcp);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(840, 170, 111, 41));
        label_15->setFont(font2);
        label_16 = new QLabel(tcp);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(840, 300, 111, 41));
        label_16->setFont(font2);
        label_17 = new QLabel(tcp);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(840, 420, 111, 41));
        label_17->setFont(font2);
        label_18 = new QLabel(tcp);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(840, 530, 111, 41));
        label_18->setFont(font2);

        retranslateUi(tcp);

        QMetaObject::connectSlotsByName(tcp);
    } // setupUi

    void retranslateUi(QWidget *tcp)
    {
        tcp->setWindowTitle(QApplication::translate("tcp", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("tcp", "TCP  \345\215\217\350\256\256", Q_NULLPTR));
        label_2->setText(QApplication::translate("tcp", "\346\272\220\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("tcp", "\347\233\256\347\232\204\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        label_4->setText(QApplication::translate("tcp", "32\344\275\215\345\272\217\345\217\267(seq)", Q_NULLPTR));
        label_5->setText(QApplication::translate("tcp", "32\344\275\215\347\241\256\350\256\244\345\272\217\345\217\267(ACK)", Q_NULLPTR));
        label_6->setText(QApplication::translate("tcp", "\346\225\260\346\215\256\345\201\217\347\247\273", Q_NULLPTR));
        label_7->setText(QApplication::translate("tcp", "\344\277\235\347\225\231\344\275\215", Q_NULLPTR));
        label_8->setText(QApplication::translate("tcp", "U A P R S F", Q_NULLPTR));
        label_9->setText(QApplication::translate("tcp", "R C S S  Y I ", Q_NULLPTR));
        label_10->setText(QApplication::translate("tcp", " G K H T N N ", Q_NULLPTR));
        label_11->setText(QApplication::translate("tcp", "\347\252\227\345\217\243\345\244\247\345\260\217", Q_NULLPTR));
        label_12->setText(QApplication::translate("tcp", "\346\240\241\351\252\214\345\222\214", Q_NULLPTR));
        label_13->setText(QApplication::translate("tcp", "\347\264\247\346\200\245\346\214\207\351\222\210", Q_NULLPTR));
        label_14->setText(QApplication::translate("tcp", "\346\272\220\346\225\260\346\215\256", Q_NULLPTR));
        label_15->setText(QApplication::translate("tcp", "\346\272\220\346\225\260\346\215\256", Q_NULLPTR));
        label_16->setText(QApplication::translate("tcp", "\346\272\220\346\225\260\346\215\256", Q_NULLPTR));
        label_17->setText(QApplication::translate("tcp", "\346\272\220\346\225\260\346\215\256", Q_NULLPTR));
        label_18->setText(QApplication::translate("tcp", "\346\272\220\346\225\260\346\215\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class tcp: public Ui_tcp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCP_H
