#include "vipzhuce.h"
#include "ui_vipzhuce.h"

vipzhuce::vipzhuce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vipzhuce)
{
    ui->setupUi(this);
}

vipzhuce::~vipzhuce()
{
    delete ui;
}
