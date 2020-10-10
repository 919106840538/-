#ifndef LOOKFOR_H
#define LOOKFOR_H

#include <QWidget>

namespace Ui {
class lookfor;
}

class lookfor : public QWidget
{
    Q_OBJECT

signals:
    void chazhao();

public:
    explicit lookfor(QWidget *parent = 0);
    QString getid();
    QString getname();
    void oon_pushButton_2_released();
    ~lookfor();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::lookfor *ui;
};

#endif // LOOKFOR_H
