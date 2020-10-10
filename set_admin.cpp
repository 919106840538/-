#include "set_admin.h"
#include "ui_set_admin.h"


set_admin::set_admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_admin)
{
    ui->setupUi(this);
    setWindowTitle("注册");

}

set_admin::~set_admin()
{
    delete ui;
}

void set_admin::oon_pushButton_2_released(){
    on_pushButton_2_released();
}

void set_admin::on_pushButton_2_released()
{
    ui->ID->setText("");
    ui->NAME->setText("");
    ui->NUMBER->setText("");
    ui->PASSWORD->setText("");
}

void set_admin::on_pushButton_released()
{
    emit zhuce();
}

QString set_admin::getID(){
    return ui->ID->text();
}
QString set_admin::getNUMBER(){
    return ui->NUMBER->text();
}
QString set_admin::getNAME(){
    return ui->NAME->text();
}
QString set_admin::getPASSWORD(){
    return ui->PASSWORD->text();
}
