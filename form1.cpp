#include "form1.h"
#include "ui_form1.h"


Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);
    ui->del->setEnabled(false); //деактивация кнопки при пустом поле
    ui->find->setEnabled(false); //деактивация кнопки при пустом поле

    connect(ui->back, SIGNAL(clicked()), this, SLOT(back())); //связь клавиши назад с возвращением к главному меню
    connect(ui->add, SIGNAL(clicked()), this, SLOT(add())); //связь клавиши добавить с открытием формы добавления
    connect(&c, &Client::cldata, this, &Form1::addlist); //сигнал с передачей данных для списка
    connect(ui->find_input, SIGNAL(textChanged(QString)), this, SLOT(check_search_button())); //проверка
    //заполенности поля для поиска
    connect(ui->delete_input, SIGNAL(textChanged(QString)), this, SLOT(check_del_button())); //проверка
    //заполненности поля для удаления
    connect(ui->find, SIGNAL(clicked()), this, SLOT(search_client())); //связь клавиши поиск и поиском клиента
    connect(ui->del, SIGNAL(clicked()), this, SLOT(delete_client())); //связь клавиши удалить с удалением клиента
    connect(ui->file, SIGNAL(clicked()), this, SLOT(load_file())); //связь клавиши загрузить данные с загрузкой данных из файла

}

void Form1::back() //функция возврата к главному меню
{
    ui->add->setEnabled(true);
    this->close();
    emit cl();
}

void Form1::add() //функция открытия формы добавления
{
    ui->add->setEnabled(false);
    c.setWindowTitle("Добавление клиента");
    c.show();
}

void Form1::delete_client() //функция удаление клиента по номеру в таблице
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
    ui->delete_input->clear();
    ui->del->setEnabled(true);
}

void Form1::search_client() //функция поиска клиента по фамилии
{
    for (int i = 0; i < mass.size(); i++)
    {
        product* obj = mass[i];
        if (ui->find_input->text() == obj->sname)
            ui->tableWidget->selectRow(i);
    }

    ui->find_input->clear();
    ui->find->setEnabled(false);
}

void Form1::addlist(QString sname, QString name, QString pname, QString num, QString mail) //функция добавления клиента в список
{
    ui->add->setEnabled(true);
    ConcreteBuilder* build = new ConcreteBuilder();
    director.set_builder(build);
    director.build_client(sname, name, pname, num, mail);
    product* p = build->GetRes();
    mass.append(p);
    p = NULL;
    fill_table();
}

void Form1::fill_table() //функция заполения и отображения таблицы
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

            if (j == 0)  item = new QTableWidgetItem(QString::number(n));
            if (j == 1) item = new QTableWidgetItem(obj->sname);
            if (j == 2) item = new QTableWidgetItem(obj->name);
            if (j == 3) item = new QTableWidgetItem(obj->pname);
            if (j == 4) item = new QTableWidgetItem(obj->num);
            if (j == 5) item = new QTableWidgetItem(obj->mail);
            ui->tableWidget->setItem(i, j, item);
        }
    }
}

void Form1::check_del_button() //функция проверки поля для удаления
{
    if (ui->delete_input->text() != "")
        ui->del->setEnabled(true);
}

void Form1::check_search_button() //функция проверки поля для поиска
{
    if (ui->find_input->text() != "")
        ui->find->setEnabled(true);
}

void Form1::load_file() //функция загрузки данных из файла
{
    QFile file;
    file.setFileName("/home/tindd/qtprojects/test/client.txt");
    if (!file.open(QIODevice::ReadOnly))
        return;
    QTextStream in(&file);
    QList<QString> l;
    while (!in.atEnd())
    {
        QString sn, n, pn, num, m;
        QString s = in.readLine();
        l.append(s.split('/'));
        sn = l[0];
        n = l[1];
        pn = l[2];
        num = l[3];
        m = l[4];
        ConcreteBuilder* build = new ConcreteBuilder();
        director.set_builder(build);
        director.build_client(sn, n, pn, num, m);
        product* pr = build->GetRes();
        mass.append(pr);
        pr = NULL;
        l.clear();
    }
    ui->file->setEnabled(false);
    fill_table();
}

Form1::~Form1()
{
    delete ui;
}
