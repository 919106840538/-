#include "changeinf.h"
#include "ui_changeinf.h"

changeinf::changeinf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::changeinf)
{
    ui->setupUi(this);
}

changeinf::~changeinf()
{
    delete ui;
}

void changeinf::on_pushButton_2_released()
{
    ui->id->clear();
    ui->sprice->clear();
}


void changeinf::oon_pushButton_2_released()
{
    on_pushButton_2_released();
}
QString changeinf::getid()
{
    return ui->id->text();
}
QString changeinf::getsprice()
{
    return ui->sprice->text();
}
void changeinf::on_pushButton_released()
{
    emit gaijia();
}
