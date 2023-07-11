#ifndef PASSTICKET_H
#define PASSTICKET_H

#include <QWidget>

namespace Ui {
class passticket;
}

class passticket : public QWidget
{
    Q_OBJECT

public:
    explicit passticket(QWidget *parent = nullptr);
    ~passticket();

signals:
    void passs(QString, QString, QString, QString); //сигнал закрытия окна заполения инф-и для возврата билета с передачей данных

private slots:
    void pass(); //функция работы с кнопкой, передача сигнала о возвратке билета

private:
    Ui::passticket *ui;
};

#endif // PASSTICKET_H
