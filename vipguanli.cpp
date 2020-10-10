#include "vipguanli.h"
#include "ui_vipguanli.h"

vipguanli::vipguanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vipguanli)
{
    ui->setupUi(this);
}

vipguanli::~vipguanli()
{
    delete ui;
}

void vipguanli::on_pushButton_released()
{
    emit chaxun();
}
