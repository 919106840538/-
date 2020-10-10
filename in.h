#ifndef IN_H
#define IN_H

#include <QWidget>

namespace Ui {
class in;
}

class in : public QWidget
{
    Q_OBJECT

signals:
    void ruku();

public:
    explicit in(QWidget *parent = 0);
    QString getid();
    QString getname();
    QString getamount();
    QString getunit();
    QString getprice();
    QString getsprice();
    void oon_pushButton_2_released();

    ~in();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::in *ui;
};

#endif // IN_H
