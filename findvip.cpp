#include "findvip.h"
#include "ui_findvip.h"

findvip::findvip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::findvip)
{
    ui->setupUi(this);
}

findvip::~findvip()
{
    delete ui;
}
