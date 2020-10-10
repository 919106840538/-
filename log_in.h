#ifndef LOG_IN_H
#define LOG_IN_H

#include <QWidget>

namespace Ui {
class log_in;
}

class log_in : public QWidget
{
    Q_OBJECT

public:
    explicit log_in(QWidget *parent = 0);
    QString getid();
    QString getpass();
    void blankpass();
    void oon_pushButton_2_released();

    ~log_in();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

signals:
    void denlu();

private:
    Ui::log_in *ui;
};

#endif // LOG_IN_H
