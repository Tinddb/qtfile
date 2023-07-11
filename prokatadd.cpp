#include "prokatadd.h"
#include "ui_prokatadd.h"

prokatadd::prokatadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prokatadd)
{
    ui->setupUi(this);
    connect(ui->add, SIGNAL(clicked()), this, SLOT(add()));
}

void prokatadd::add() //кнопка, реагирующая на нажатие и передающая данные
{
    this->close();
    emit clwi(ui->film->text(), ui->sname->text(), ui->name->text(), ui->pl->text());
    ui->film->clear();
    ui->sname->clear();
    ui->name->clear();
    ui->pl->clear();
}

prokatadd::~prokatadd()
{
    delete ui;
}
