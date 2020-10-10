#ifndef CHANGEINF_H
#define CHANGEINF_H

#include <QWidget>

namespace Ui {
class changeinf;
}

class changeinf : public QWidget
{
    Q_OBJECT

public:
    explicit changeinf(QWidget *parent = 0);
    void oon_pushButton_2_released();
    QString getid();
    QString getsprice();
    ~changeinf();

signals:

    void gaijia();

private slots:
    void on_pushButton_2_released();

    void on_pushButton_released();

private:
    Ui::changeinf *ui;
};

#endif // CHANGEINF_H
