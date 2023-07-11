#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "builder.h"


class Director //класс управления методами строителя
{
private:
    builder* build;

public:
    void set_builder(builder* build); //установка нужного строителя
    void build_kino(QString name, QString year, QString zhanr, QString time, QString places); //строение инф-и о фильме
    void build_client(QString name, QString sname, QString pname, QString num, QString mail); //строение инф-и о клиенте
    void build_ticket(QString film, QString sname, QString name, QString pl); //строение инф-и о билете
};

#endif // DIRECTOR_H
