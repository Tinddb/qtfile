#include "films.h"
#include "ui_films.h"

films::films(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::films)
{
    ui->setupUi(this);
}

films::~films()
{
    delete ui;
}
