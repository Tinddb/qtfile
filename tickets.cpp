#include "tickets.h"
#include "ui_tickets.h"

tickets::tickets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tickets)
{
    ui->find->setEnabled(false);
    ui->setupUi(this);
    connect(ui->back, SIGNAL(clicked()), this, SLOT(back()));
}

void tickets::back()
{
    this->close();
    emit clo();
}

tickets::~tickets()
{
    delete ui;
}
