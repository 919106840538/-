#ifndef VIPZHUCE_H
#define VIPZHUCE_H

#include <QWidget>

namespace Ui {
class vipzhuce;
}

class vipzhuce : public QWidget
{
    Q_OBJECT

public:
    explicit vipzhuce(QWidget *parent = 0);
    ~vipzhuce();

private:
    Ui::vipzhuce *ui;
};

#endif // VIPZHUCE_H
