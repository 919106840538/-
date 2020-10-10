#include "in.h"
#include "ui_in.h"

in::in(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::in)
{
    ui->setupUi(this);
    setWindowTitle("商品入库");
}

in::~in()
{
    delete ui;
}

void in::on_pushButton_released()
{
    emit ruku();
}

QString in::getsprice()
{
    return ui->price_2->text();
}

QString in::getid(){
    return ui->id->text();
}
QString in::getname(){
    return ui->name->text();
}
QString in::getamount(){
    return ui->amount->text();
}
QString in::getunit(){
    return ui->unit->text();
}
QString in::getprice(){
    return ui->price->text();
}
void in::oon_pushButton_2_released()
{
    on_pushButton_2_released();
}

void in::on_pushButton_2_released()
{
    ui->id->clear();
    ui->name->clear();
    ui->amount->clear();
    ui->unit->clear();
    ui->price->clear();
    ui->price_2->clear();
}
