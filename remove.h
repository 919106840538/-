#ifndef REMOVE_H
#define REMOVE_H

#include <QWidget>

namespace Ui {
class REmove;
}

class REmove : public QWidget
{
    Q_OBJECT
signals:
    void xiajia();
public:
    explicit REmove(QWidget *parent = 0);
    QString getid();
    QString getname();
    void oon_pushButton_2_released();
    ~REmove();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::REmove *ui;
};

#endif // REMOVE_H
