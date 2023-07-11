#include "kino.h"
#include "ui_kino.h"

kino::kino(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kino)
{
    ui->setupUi(this);
    ui->del->setEnabled(false); //деактивация кнопки при пустом поле
    ui->find->setEnabled(false); //деактивация кнопки при пустом поле

    connect(ui->back, SIGNAL(clicked()), this, SLOT(back())); //связь клавиши назад с возвращением к главному меню
    connect(ui->addd, SIGNAL(clicked()), this, SLOT(add())); //связь клавиши добавить с открытием формы добавления
    connect(&ka, &kinoadd::cll, this, &kino::addlist); //сигнал с передачей данных для списка
    connect(ui->delete_input, SIGNAL(textChanged(QString)), this, SLOT(check_del_button())); //проверка
    //заполенности поля для поиска
    connect(ui->find_input, SIGNAL(textChanged(QString)), this, SLOT(check_search_button())); //проверка
    //заполненности поля для удаления
    connect(ui->del, SIGNAL(clicked()), this, SLOT(del_el())); //связь клавиши удалить с удалением фильма
    connect(ui->find, SIGNAL(clicked()), this, SLOT(search_el())); //связь клавиши поиск с поиском фильма
    connect(ui->file, SIGNAL(clicked()), this, SLOT(load_file())); //связь клавиши загрузить данные с загрузкой данных из файла
}

void kino::back() //функция возвращения назад
{
    this->close();
    ui->addd->setEnabled(true);
    emit cc();
}

void kino::add() //функция, вызывающая окно добавления
{
    ui->addd->setEnabled(false);
    ka.setWindowTitle("Добавление фильма");
    ka.show();
}

void kino::addlist(QString name, QString year, QString zhanr, QString time, QString pl) //функция, отвечающая за заполнение списка
{
   ui->addd->setEnabled(true);
   ConcreteBuilder* build = new ConcreteBuilder();
   director.set_builder(build);
   director.build_kino(name, year, zhanr, time, pl);
   product* p = build->GetRes();
   mass.append(p);
   build = NULL;
   p = NULL;
   fill_table();
}

void kino::fill_table() //функция заполения полей таблицы
{
    ui->tableWidget->clearContents();
    int n = 0;
    for (int i = 0; i < mass.size(); i++)
    {
        product* obj = mass[i];
        n++;
        for (int j = 0; j < 6; j++)
        {
            QTableWidgetItem *item;
            if (j == 0) item = new QTableWidgetItem(QString::number(n));
            if (j == 1) item = new QTableWidgetItem(obj->name);
            if (j == 2) item = new QTableWidgetItem(obj->year);
            if (j == 3)item = new QTableWidgetItem(obj->zhanr);
            if (j == 4) item = new QTableWidgetItem(obj->time);
            if (j == 5) item = new QTableWidgetItem(obj->places);
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

void kino::check_del_button() //функция проверки кнопки удаления
{
    if (ui->delete_input->text() != "")
        ui->del->setEnabled(true);
}

void kino::check_search_button() //функция проверки кнопки поиска
{
    if (ui->find_input->text() != "")
        ui->find->setEnabled(true);
}

void kino::search_el() //функция поиска фильма по названию
{

    for (int i = 0; i < mass.size(); i++)
    {
        product* obj = mass[i];
        if (ui->find_input->text() == obj->name)
        {
            ui->tableWidget->selectRow(i);
        }
    }
    ui->find_input->setText("");
    ui->find->setEnabled(false);

}

void kino::del_el() //функция удаления элемента по номеру в таблице
{
    if (ui->delete_input->text().toInt() - 1 < mass.size())
    {
        mass.removeAt(ui->delete_input->text().toInt() - 1);
        fill_table();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Ошибка!");
        msgBox.setStyleSheet("QLabel{min-width: 100px;}");
        QTimer::singleShot(1000, &msgBox, SLOT(close()));
        msgBox.exec();
    }
    if (mass.size() == 0)
        ui->file->setEnabled(true);
    ui->delete_input->setText("");
    ui->del->setEnabled(false);
}

void kino::load_file() //функция загрузки из файла
{
    QFile file;
    file.setFileName("/home/tindd/qtprojects/test/kino.txt");
    if (!file.open(QIODevice::ReadOnly))
        return;
    QTextStream in(&file);
    QList<QString> l;
    while (!in.atEnd())
    {
        QString n, y, zh, t, p;
        QString s = in.readLine();
        l.append(s.split('/'));
        n = l[0];
        y = l[1];
        zh = l[2];
        t = l[3];
        p = l[4];
        ConcreteBuilder* build = new ConcreteBuilder();
        director.set_builder(build);
        director.build_kino(n, y, zh, t, p);
        product* pr = build->GetRes();
        mass.append(pr);
        build = NULL;
        pr = NULL;
        l.clear();
    }
    ui->file->setEnabled(false);
    fill_table();
}

void kino::reset() //функция обновления данных в таблице
{
    fill_table();
}

kino::~kino()
{
    delete ui;
}
