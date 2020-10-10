#include "remove.h"
#include "ui_remove.h"

REmove::REmove(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::REmove)
{
    ui->setupUi(this);
}

REmove::~REmove()
{
    delete ui;
}

void REmove::on_pushButton_released()
{
    emit xiajia();
}

QString REmove::getid()
{
    return ui->id->text();
}

QString REmove::getname()
{
    return ui->sprice->text();
}

void REmove::oon_pushButton_2_released()
{
    on_pushButton_2_released();
}
void REmove::on_pushButton_2_released()
{
    ui->id->clear();
    ui->sprice->clear();
}
