#ifndef FINDVIP_H
#define FINDVIP_H

#include <QWidget>

namespace Ui {
class findvip;
}

class findvip : public QWidget
{
    Q_OBJECT

public:
    explicit findvip(QWidget *parent = 0);
    ~findvip();

private:
    Ui::findvip *ui;
};

#endif // FINDVIP_H
