#ifndef VIPGUANLI_H
#define VIPGUANLI_H

#include <QWidget>

namespace Ui {
class vipguanli;
}

class vipguanli : public QWidget
{
    Q_OBJECT

signals:
    void chaxun();
public:
    explicit vipguanli(QWidget *parent = 0);
    ~vipguanli();

private slots:
    void on_pushButton_released();

private:
    Ui::vipguanli *ui;
};

#endif // VIPGUANLI_H
