#ifndef FILMS_H
#define FILMS_H

#include <QWidget>

namespace Ui {
class films;
}

class films : public QWidget
{
    Q_OBJECT

public:
    explicit films(QWidget *parent = nullptr);
    ~films();

private:
    Ui::films *ui;
};

#endif // FILMS_H
