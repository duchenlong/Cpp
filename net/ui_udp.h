/********************************************************************************
** Form generated from reading UI file 'udp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDP_H
#define UI_UDP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_udp
{
public:
    QLabel *label;
    QLineEdit *sport;
    QLineEdit *dport;
    QLineEdit *srcip;
    QLineEdit *descip;
    QLineEdit *type;
    QLineEdit *lenW;
    QLineEdit *checkSum;
    QLineEdit *len;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *data1;
    QLineEdit *data2;
    QLabel *label_14;
    QLabel *label_15;

    void setupUi(QWidget *udp)
    {
        if (udp->objectName().isEmpty())
            udp->setObjectName(QStringLiteral("udp"));
        udp->resize(1122, 445);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        udp->setFont(font);
        label = new QLabel(udp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(470, 0, 151, 71));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        sport = new QLineEdit(udp);
        sport->setObjectName(QStringLiteral("sport"));
        sport->setGeometry(QRect(100, 250, 271, 61));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setWeight(50);
        sport->setFont(font2);
        sport->setFocusPolicy(Qt::NoFocus);
        sport->setAlignment(Qt::AlignCenter);
        sport->setReadOnly(true);
        dport = new QLineEdit(udp);
        dport->setObjectName(QStringLiteral("dport"));
        dport->setGeometry(QRect(370, 250, 271, 61));
        dport->setFont(font2);
        dport->setFocusPolicy(Qt::NoFocus);
        dport->setAlignment(Qt::AlignCenter);
        dport->setReadOnly(true);
        srcip = new QLineEdit(udp);
        srcip->setObjectName(QStringLiteral("srcip"));
        srcip->setGeometry(QRect(200, 110, 261, 51));
        srcip->setFont(font2);
        srcip->setFocusPolicy(Qt::NoFocus);
        srcip->setAlignment(Qt::AlignCenter);
        srcip->setReadOnly(true);
        descip = new QLineEdit(udp);
        descip->setObjectName(QStringLiteral("descip"));
        descip->setGeometry(QRect(460, 110, 261, 51));
        descip->setFont(font2);
        descip->setFocusPolicy(Qt::NoFocus);
        descip->setAlignment(Qt::AlignCenter);
        descip->setReadOnly(true);
        type = new QLineEdit(udp);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(720, 110, 121, 51));
        type->setFont(font2);
        type->setFocusPolicy(Qt::NoFocus);
        type->setAlignment(Qt::AlignCenter);
        type->setReadOnly(true);
        lenW = new QLineEdit(udp);
        lenW->setObjectName(QStringLiteral("lenW"));
        lenW->setGeometry(QRect(840, 110, 121, 51));
        lenW->setFont(font2);
        lenW->setFocusPolicy(Qt::NoFocus);
        lenW->setAlignment(Qt::AlignCenter);
        lenW->setReadOnly(true);
        checkSum = new QLineEdit(udp);
        checkSum->setObjectName(QStringLiteral("checkSum"));
        checkSum->setGeometry(QRect(370, 360, 271, 61));
        checkSum->setFont(font2);
        checkSum->setFocusPolicy(Qt::NoFocus);
        checkSum->setAlignment(Qt::AlignCenter);
        checkSum->setReadOnly(true);
        len = new QLineEdit(udp);
        len->setObjectName(QStringLiteral("len"));
        len->setGeometry(QRect(100, 360, 271, 61));
        len->setFont(font2);
        len->setFocusPolicy(Qt::NoFocus);
        len->setAlignment(Qt::AlignCenter);
        len->setReadOnly(true);
        label_2 = new QLabel(udp);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 120, 71, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei"));
        font3.setPointSize(13);
        label_2->setFont(font3);
        label_3 = new QLabel(udp);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 70, 101, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Microsoft YaHei"));
        font4.setPointSize(13);
        font4.setBold(true);
        font4.setWeight(75);
        label_3->setFont(font4);
        label_4 = new QLabel(udp);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(530, 70, 131, 31));
        label_4->setFont(font4);
        label_5 = new QLabel(udp);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(750, 70, 51, 31));
        label_5->setFont(font4);
        label_6 = new QLabel(udp);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(870, 70, 51, 31));
        label_6->setFont(font4);
        label_7 = new QLabel(udp);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(210, 210, 91, 31));
        label_7->setFont(font4);
        label_8 = new QLabel(udp);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(450, 210, 91, 31));
        label_8->setFont(font4);
        label_9 = new QLabel(udp);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(200, 320, 91, 31));
        label_9->setFont(font4);
        label_10 = new QLabel(udp);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(470, 320, 91, 31));
        label_10->setFont(font4);
        data1 = new QLineEdit(udp);
        data1->setObjectName(QStringLiteral("data1"));
        data1->setGeometry(QRect(670, 250, 441, 61));
        data1->setFont(font2);
        data1->setFocusPolicy(Qt::NoFocus);
        data1->setAlignment(Qt::AlignCenter);
        data1->setReadOnly(true);
        data2 = new QLineEdit(udp);
        data2->setObjectName(QStringLiteral("data2"));
        data2->setGeometry(QRect(670, 360, 441, 61));
        data2->setFont(font2);
        data2->setFocusPolicy(Qt::NoFocus);
        data2->setAlignment(Qt::AlignCenter);
        data2->setReadOnly(true);
        label_14 = new QLabel(udp);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(870, 210, 111, 41));
        QFont font5;
        font5.setFamily(QStringLiteral("Microsoft YaHei"));
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        label_14->setFont(font5);
        label_15 = new QLabel(udp);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(870, 320, 111, 41));
        label_15->setFont(font5);

        retranslateUi(udp);

        QMetaObject::connectSlotsByName(udp);
    } // setupUi

    void retranslateUi(QWidget *udp)
    {
        udp->setWindowTitle(QApplication::translate("udp", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("udp", "UDP  \345\215\217\350\256\256", Q_NULLPTR));
        type->setText(QApplication::translate("udp", "17", Q_NULLPTR));
        label_2->setText(QApplication::translate("udp", "\344\274\252\351\246\226\351\203\250", Q_NULLPTR));
        label_3->setText(QApplication::translate("udp", "\346\272\220IP\345\234\260\345\235\200", Q_NULLPTR));
        label_4->setText(QApplication::translate("udp", "\347\233\256\347\232\204IP\345\234\260\345\235\200", Q_NULLPTR));
        label_5->setText(QApplication::translate("udp", "\347\261\273\345\236\213", Q_NULLPTR));
        label_6->setText(QApplication::translate("udp", "\351\225\277\345\272\246", Q_NULLPTR));
        label_7->setText(QApplication::translate("udp", "\346\272\220\347\253\257\345\217\243", Q_NULLPTR));
        label_8->setText(QApplication::translate("udp", "\347\233\256\347\232\204\347\253\257\345\217\243", Q_NULLPTR));
        label_9->setText(QApplication::translate("udp", "\351\225\277\345\272\246 ", Q_NULLPTR));
        label_10->setText(QApplication::translate("udp", "\346\240\241\351\252\214\345\222\214", Q_NULLPTR));
        label_14->setText(QApplication::translate("udp", "\346\272\220\346\225\260\346\215\256", Q_NULLPTR));
        label_15->setText(QApplication::translate("udp", "\346\272\220\346\225\260\346\215\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class udp: public Ui_udp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDP_H
