/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QLineEdit *idx;
    QLabel *label;
    QLabel *label_2;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(621, 455);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 260, 321, 51));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QLatin1String("QPushButton { background-color:rgb(0, 255, 0); border:2px solid #014F84; color: rgb(rgb(0, 0, 0)); }\n"
"QPushButton:hover { background-color:rgb(200, 194, 181); }\n"
""));
        pushButton->setFlat(false);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 340, 171, 61));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QLatin1String("QPushButton { background-color:rgb(170, 255, 255); border:2px solid #014F84; color: rgb(rgb(0, 0, 0)); }\n"
"QPushButton:hover { background-color: rgb(200, 194, 181); }"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 340, 171, 61));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QLatin1String("QPushButton { background-color:rgb(170, 255, 255); border:2px solid #014F84; color: rgb(rgb(0, 0, 0)); }\n"
"QPushButton:hover { background-color: rgb(200, 194, 181); }"));
        pushButton_3->setFlat(false);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 100, 321, 51));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_5->setFont(font3);
        pushButton_5->setAutoDefault(true);
        idx = new QLineEdit(centralwidget);
        idx->setObjectName(QStringLiteral("idx"));
        idx->setGeometry(QRect(260, 200, 111, 41));
        idx->setFont(font3);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 190, 221, 61));
        QFont font4;
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 20, 281, 61));
        QFont font5;
        font5.setPointSize(20);
        font5.setBold(true);
        font5.setWeight(75);
        label_2->setFont(font5);
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(390, 212, 171, 21));
        progressBar->setValue(0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 621, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton->setDefault(true);
        pushButton_2->setDefault(true);
        pushButton_3->setDefault(true);
        pushButton_5->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\351\232\217\346\234\272\346\212\223\345\217\226\344\270\200\344\270\252\346\225\260\346\215\256\345\214\205", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "TCP  \345\215\217\350\256\256\346\225\260\346\215\256\345\214\205", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "UDP  \345\215\217\350\256\256\346\225\260\346\215\256\345\214\205", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\344\270\273\346\234\272\347\275\221\345\215\241\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\347\275\221\345\215\241\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\347\275\221\347\273\234\345\215\217\350\256\256\345\210\206\346\236\220\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
