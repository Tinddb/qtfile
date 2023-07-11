#include "passticket.h"
#include "ui_passticket.h"

passticket::passticket(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::passticket)
{
    ui->setupUi(this);
    connect(ui->pass, SIGNAL(clicked()), this, SLOT(pass())); //коннект для работы с кнопкой
}

void passticket::pass() //кнопка, закрывающая окно и передающая данные из полей
{
    this->close();
    emit passs(ui->film->text(), ui->sname->text(), ui->name->text(), ui->pl->text());
    ui->film->clear();
    ui->sname->clear();
    ui->name->clear();
    ui->pl->clear();
}
passticket::~passticket()
{
    delete ui;
}
