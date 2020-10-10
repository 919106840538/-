#ifndef SET_ADMIN_H
#define SET_ADMIN_H

#include <QWidget>

namespace Ui {
class set_admin;
}

class set_admin : public QWidget
{
    Q_OBJECT

signals:
    void zhuce();

public:
    explicit set_admin(QWidget *parent = 0);
    QString getID();
    QString getNAME();
    QString getPASSWORD();
    QString getNUMBER();
    ~set_admin();
    void oon_pushButton_2_released();

private slots:
    void on_pushButton_released();
    void on_pushButton_2_released();

private:
    Ui::set_admin *ui;
};

#endif // SET_ADMIN_H
