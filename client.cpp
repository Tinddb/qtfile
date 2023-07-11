#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    ui->add->setEnabled(false);
    connect(ui->add, SIGNAL(clicked()), this, SLOT(add())); //связь клавиши добавить и функции подачи сигнала
    connect(ui->mail, SIGNAL(textChanged(QString)), this, SLOT(check())); //проверка заполенности полей
}

void Client::add() //функция закрытия окна добавления и подача сигнала с данным
{
    emit cldata(ui->sname->text(), ui->name->text(), ui->parent_name->text(), ui->num->text(), ui->mail->text());
    this->close();
    ui->name->clear();
    ui->sname->clear();
    ui->parent_name->clear();
    ui->num->clear();
    ui->mail->clear();
}

void Client::check() //функция проверки заполенности полей
{
    if (ui->name->text() != "" && ui->sname->text() != "" && ui->parent_name->text() != "" && ui->num->text() != "" && ui->mail->text() != "")
        ui->add->setEnabled(true);
}

Client::~Client()
{
    delete ui;
}
