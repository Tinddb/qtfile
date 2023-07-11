    #ifndef PROKATADD_H
    #define PROKATADD_H

    #include <QWidget>

    namespace Ui {
    class prokatadd;
    }

    class prokatadd : public QWidget
    {
        Q_OBJECT

    public:
        explicit prokatadd(QWidget *parent = nullptr);
        ~prokatadd();

    signals:
        void clwi(QString film, QString sname, QString name, QString pl); //сигнал для закрытия окна покупки билета
        //и передачи данных

    private slots:
        void add(); //функция, отслеживающая нажатие на клавишу добавить, для подачи сигнала

    private:
        Ui::prokatadd *ui;
    };

    #endif // PROKATADD_H
