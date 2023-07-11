#ifndef KINOADD_H
#define KINOADD_H

#include <QWidget>
#include <QObject>

namespace Ui {
class kinoadd;
}

class kinoadd : public QWidget
{
    Q_OBJECT

public:
    explicit kinoadd(QWidget *parent = nullptr);
    ~kinoadd();


public slots:
    void add(); //функция, отслуживающая нажатие на кнопку добавить
    void check(); //функция, проверяющая заполненность полей

signals:
    void cll(QString, QString, QString, QString, QString); //сигнал закрытия окна ввода данных о фильме, передача
    //данных в окно с фильмами

private:
    Ui::kinoadd *ui;
};

#endif // KINOADD_H
