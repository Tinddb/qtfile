#include "nnn.h"
#include "ui_nnn.h"

nnn::nnn(Form1* cl, kino* k, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nnn)
{
    ui->setupUi(this);
    client = cl;
    Kino = k;

    connect(ui->back, SIGNAL(clicked()), this, SLOT(back())); //работа с кнопками
    connect(ui->buy, SIGNAL(clicked()), this, SLOT(buy()));
    connect(ui->pass, SIGNAL(clicked()), this, SLOT(pass()));
    connect(&padd, &prokatadd::clwi, this, &nnn::addlist); //отслеживание сигнала закрытия окна
    connect(&pticket, &passticket::passs, this, &nnn::passlist);

}

void nnn::back() //возвращение назад
{
    this->close();
    ui->buy->setEnabled(true);
    emit z();
}

void nnn::buy() //нажатие на клавишу купить билет
{
    if (Kino->mass.isEmpty() && client->mass.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Базы данных пусты!");
        msgBox.setStyleSheet("QLabel{min-width: 400px;}");
        QTimer::singleShot(1000, &msgBox, SLOT(close()));
        msgBox.exec();
    }
    else
    {
        ui->buy->setEnabled(false);
        padd.setWindowTitle("Покупка билета");
        padd.show();
    }
}

void nnn::addlist(QString film, QString sname, QString name, QString pl) //добавление элемента в список
{
    ui->buy->setEnabled(true);
    QString sn = "";
    QString f = "";
    QString namme = "";
    int place = 0;
    bool flag = 0, flag2 = 0;
    for (int i = 0; i < client->mass.size(); i++)
    {
        product* obj = client->mass[i];
        if (sname == obj->sname && name == obj->name)
        {
            sn = sname;
            namme = name;
            flag = 1;
            break;
        }
    }

    for (int i = 0; i < Kino->mass.size(); i++)
    {
        product* obj = Kino->mass[i];
        if (film == obj->name)
        {
            f = film;
            place = obj->places.toInt();
            if (place - pl.toInt() > 0)
            {
                flag2 = 1;
                obj->places = QString::number(obj->places.toInt() - pl.toInt());
            }
        }
    }
    if (flag && flag2)
    {
        ConcreteBuilder* build = new ConcreteBuilder();
        director.set_builder(build);
        director.build_ticket(film, sname, name, pl);
        product* p = build->GetRes();
        list.append(p);
        Kino->reset();
        p = NULL;
        fill_table();
    }
}

void nnn::fill_table() //заполнение таблицы
{
    ui->tableWidget->clearContents();
    for (int i = 0; i < list.size(); i++)
    {
        product* pr = list[i];
        for (int j = 0; j < 5; j++)
        {
            QTableWidgetItem* item;
            if (j == 0) item = new QTableWidgetItem(QString::number(i + 1));
            if (j == 1) item = new QTableWidgetItem(pr->film);
            if (j == 2) item = new QTableWidgetItem(pr->sname);
            if (j == 3) item = new QTableWidgetItem(pr->name);
            if (j == 4) item = new QTableWidgetItem(pr->places);
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

void nnn::pass() //нажатие на клавишу сдачи билета
{
    if (Kino->mass.isEmpty() && client->mass.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Базы данных пусты!");
        msgBox.setStyleSheet("QLabel{min-width: 400px;}");
        QTimer::singleShot(1000, &msgBox, SLOT(close()));
        msgBox.exec();
    }
    else if (list.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Нет купленных билетов!");
        msgBox.setStyleSheet("QLabel{min-width: 400px;}");
        QTimer::singleShot(1000, &msgBox, SLOT(close()));
        msgBox.exec();
    }

    else
    {
        ui->pass->setEnabled(false);
        pticket.setWindowTitle("Сдача билета");
        pticket.show();
    }
}

void nnn::passlist(QString film, QString sname, QString name, QString pl) //удаление элемента из списка/редактироваие
{
    ui->pass->setEnabled(true);
    for (int i = 0; i < list.size(); i++)
    {
        product* obj = list[i];
        if (obj->film == film && obj->sname == sname && obj->name == name)
        {
            if (obj->places.toInt() == pl.toInt())
            {
                for (int j = 0; j < Kino->mass.size(); j++)
                {
                    product* pr = Kino->mass[j];
                    if (pr->name == film)
                    {
                        pr->places = QString::number(pr->places.toInt() + pl.toInt());
                    }
                }
                list.removeAt(i);
            }
            else if (obj->places.toInt() > pl.toInt())
            {
                for (int j = 0; j < Kino->mass.size(); j++)
                {
                    product* pr = Kino->mass[j];
                    if (pr->name == film)
                    {
                        pr->places = QString::number(pr->places.toInt() + pl.toInt());
                    }
                }
                obj->places = QString::number(obj->places.toInt() - pl.toInt());
            }
            Kino->reset();
            fill_table();
        }
    }
}

nnn::~nnn()
{
    delete ui;
}
