#include "lookfor.h"
#include "ui_lookfor.h"

lookfor::lookfor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lookfor)
{
    ui->setupUi(this);
}

lookfor::~lookfor()
{
    delete ui;
}

void lookfor::on_pushButton_released()
{
    emit chazhao();
}

void lookfor::on_pushButton_2_released()
{
    ui->id->clear();
    ui->sprice->clear();
}

void lookfor::oon_pushButton_2_released()
{
    on_pushButton_2_released();
}

QString lookfor::getid(){
    return ui->id->text();
}

QString lookfor::getname(){
    return ui->sprice->text();
}
