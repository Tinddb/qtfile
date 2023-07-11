#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    k = new kino();
    form = new Form1();
    nn = new nnn(form, k);
    ui->choose->clear();
    ui->choose->addItem("Клиенты");
    ui->choose->addItem("Фильмы");
    ui->choose->addItem("Билеты");

    connect(k, &kino::cc, this, &MainWindow::show); //сигнал возврата к главному меню
    connect(ui->press, SIGNAL(clicked()), this, SLOT(choose())); //связь кнопки в главном меню с выбором подменю
    connect(form, &Form1::cl, this, &MainWindow::show); //сигнал возврата к главному меню
    connect(nn, &nnn::z, this, &MainWindow::show);  //сигнал возврата к главному меню

}

void MainWindow::choose() //функция выбора подменю в главном меню
{
    if (ui->choose->currentText() == "Фильмы") //работа с фильмами
    {
        k->setWindowTitle("Фильмы");
        k->show();
        this->close();
    }
    else if (ui->choose->currentText() == "Клиенты") //работа с клиентами
    {
        form->setWindowTitle("Клиенты");
        form->show();
        this->close();
    }
    else if (ui->choose->currentText() == "Билеты") //работа с билетами
    {
        nn->setWindowTitle("Билеты");
        nn->show();
        this->close();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

