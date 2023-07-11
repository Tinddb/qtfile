#include "concretebuilder.h"

ConcreteBuilder::ConcreteBuilder() //конструктор строителя
{
    this->Reset();
}

ConcreteBuilder::~ConcreteBuilder()
{
    delete pr;
}

void ConcreteBuilder::Reset() //обновление данных
{
    this->pr = new product();
}

void ConcreteBuilder::Buildkino(QString name, QString year, QString zhanr, QString time, QString places) const
{ //конструктор строителя данных о фильме
    this->pr->name = name;
    this->pr->zhanr = zhanr;
    this->pr->year = year;
    this->pr->time = time;
    this->pr->places = places;
}

void ConcreteBuilder::Buildclient(QString sname, QString name, QString pname, QString num, QString mail) const
{ //конструктор строителя данных о клиенте
    this->pr->name = name;
    this->pr->sname = sname;
    this->pr->pname = pname;
    this->pr->num = num;
    this->pr->mail = mail;
}

void ConcreteBuilder::Buildticket(QString film, QString sname, QString name, QString pl) const
{ //конструктор строителя данных о билете
    this->pr->film = film;
    this->pr->sname = sname;
    this->pr->name = name;
    this->pr->places = pl;
}

 product* ConcreteBuilder::GetRes()
 { //функция, вовзрвращающая результат работы строителя
     product* res = this->pr;
     this->Reset();
     return res;
 }
