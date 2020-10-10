#include "log_in.h"
#include "ui_log_in.h"

log_in::log_in(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::log_in)
{
    ui->setupUi(this);
    setWindowTitle("登录");
}

log_in::~log_in()
{
    delete ui;
}

void log_in::on_pushButton_released()
{
    emit denlu();
}

QString log_in::getid(){
    return ui->ID->text();
}
QString log_in::getpass(){
    return ui->PASSWORD->text();
}

void log_in::on_pushButton_2_released()
{
    ui->ID->setText("");
    blankpass();
}

void log_in::oon_pushButton_2_released()
{
    ui->ID->setText("");
    blankpass();
}
void log_in::blankpass()
{
    ui->PASSWORD->setText("");
}
