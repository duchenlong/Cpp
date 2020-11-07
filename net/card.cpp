#include "card.h"
#include "ui_card.h"

card::card(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::card),_idx(-1)
{
    ui->setupUi(this);
    setWindowTitle("主机网卡信息");
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table->horizontalHeader()->setMinimumHeight(30);
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 设置表格
    ui->table->setColumnCount(2);       // 2 列  网卡名称，网卡描述
    ui->table->setHorizontalHeaderLabels(QStringList() << "网卡名称" << "网卡描述");

    ui->table->setRowCount(::size);     // size 行
    pcap_if_t* cur = ::allNetwork;
    int idx = 0;
    while(cur) {
        ui->table->setItem(idx,0,new QTableWidgetItem(cur->name));
        ui->table->setItem(idx,1,new QTableWidgetItem(cur->description));

        cur = cur->next;
        idx++;
    }

    QImage* image1 = new QImage();
    QPalette* palette = new  QPalette();
    image1->load("./1.jpg");
    palette->setBrush(this->backgroundRole(),QBrush(*image1));
    setPalette(*palette);
}

card::~card()
{
    delete ui;
}

void card::on_table_itemDoubleClicked(QTableWidgetItem *item)
{
    // qDebug() << item->row();
    this->_idx = item->row();
    this->buf = QString::fromStdString(GetId());
    //qDebug() << buf;
    on_closeButton_clicked();
}

std::string card::GetId() {
    return to_string(_idx + 1);
}

void card::on_closeButton_clicked()
{
    qDebug() << buf;
    emit signalSend(buf);
    this->close();
}
