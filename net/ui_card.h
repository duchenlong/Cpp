/********************************************************************************
** Form generated from reading UI file 'card.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARD_H
#define UI_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_card
{
public:
    QTableWidget *table;
    QLabel *label;
    QPushButton *closeButton;

    void setupUi(QWidget *card)
    {
        if (card->objectName().isEmpty())
            card->setObjectName(QStringLiteral("card"));
        card->resize(1333, 558);
        table = new QTableWidget(card);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(20, 90, 1301, 451));
        QFont font;
        font.setPointSize(11);
        table->setFont(font);
        table->setFrameShape(QFrame::Panel);
        table->setColumnCount(0);
        table->horizontalHeader()->setStretchLastSection(true);
        label = new QLabel(card);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(470, 10, 521, 81));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        closeButton = new QPushButton(card);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(1150, 20, 141, 51));

        retranslateUi(card);

        closeButton->setDefault(true);


        QMetaObject::connectSlotsByName(card);
    } // setupUi

    void retranslateUi(QWidget *card)
    {
        card->setWindowTitle(QApplication::translate("card", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("card", "\344\270\273\346\234\272\347\275\221\345\215\241\344\277\241\346\201\257 (\345\217\214\345\207\273\345\217\257\351\200\211\346\213\251\347\275\221\345\215\241)", Q_NULLPTR));
        closeButton->setText(QApplication::translate("card", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class card: public Ui_card {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARD_H
