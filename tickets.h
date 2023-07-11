#ifndef TICKETS_H
#define TICKETS_H

#include <QWidget>

namespace Ui {
class tickets;
}

class tickets : public QWidget
{
    Q_OBJECT

public:
    explicit tickets(QWidget *parent = nullptr);
    ~tickets();

signals:
    void clo();

private:
    void back();
    Ui::tickets *ui;
};

#endif // TICKETS_H
