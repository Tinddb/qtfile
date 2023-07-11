#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>



namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);

    ~Client();

signals:
    void cldata(QString name, QString sname, QString pname, QString num, QString mail); //сигнал закрытия окна добавления
    //передача данных в окно о клиентах

private slots:
    void add(); //функция, обрабатывающая нажатие на кноgку добавить
    void check();//функция, проверяющая заполненность полей

private:
    Ui::Client *ui;
};

#endif // CLIENT_H
