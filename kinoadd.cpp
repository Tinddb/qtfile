#include "kinoadd.h"
#include "ui_kinoadd.h"

kinoadd::kinoadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kinoadd)
{
    ui->setupUi(this);
    ui->add->setEnabled(false);
    connect(ui->add, SIGNAL(clicked()), this, SLOT(add()));
    ui->zhanr->clear();
    ui->zhanr->addItem("Комедия");
    ui->zhanr->addItem("Драма");
    ui->zhanr->addItem("Триллер");
    ui->zhanr->addItem("Фантастика");
    ui->zhanr->addItem("Мультфильм");
    connect(ui->time, SIGNAL(textChanged(QString)), this, SLOT(check()));
}

void kinoadd::add() //функция закрытия окна добавления и передача введеных данных
{
    emit cll(ui->n->text(), ui->year->text(), ui->zhanr->currentText(), ui->time->text(), ui->place->text());
    this->close();
    ui->n->clear();
    ui->year->clear();
    ui->zhanr->setCurrentText("Комедия");
    ui->time->clear();
}

void kinoadd::check() //функция провеки заполенности полей
{
    if (ui->n->text() != "" && ui->year->text() != "" && ui->time->text() != "" && ui->zhanr->currentText() != "")
    {
        ui->add->setEnabled(true);
    }
}


kinoadd::~kinoadd()
{
    delete ui;
}
