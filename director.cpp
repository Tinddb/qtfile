#include "director.h"

void Director::set_builder(builder *build) //функция выбора строителя
{
    this->build = build;
}

void Director::build_kino(QString name, QString year, QString zhanr, QString time, QString places)
{ //выбор стрителя данных о фильме
    this->build->Buildkino(name, year, zhanr, time, places);
}

void Director::build_client(QString sname, QString name, QString pname, QString num, QString mail)
{ //выбор строителя данных о клинте
    this->build->Buildclient(sname, name, pname, num, mail);
}

void Director::build_ticket(QString film, QString sname, QString name, QString pl)
{ //выбор строителя данных о билете
    this->build->Buildticket(film, sname, name, pl);
}
