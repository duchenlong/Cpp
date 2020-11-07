#ifndef NETCARD_H
#define NETCARD_H

#include <QWidget>

namespace Ui {
class netCard;
}

class netCard : public QWidget
{
    Q_OBJECT

public:
    explicit netCard(QWidget *parent = nullptr);
    ~netCard();

private slots:

private:
    Ui::netCard *ui;
};

#endif // NETCARD_H
