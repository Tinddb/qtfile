#ifndef BUILDER_H
#define BUILDER_H

#include <QObject>
#include <QWidget>

#include "product.h"

//интерфейс строителя, объявление создающих методов для других классов
class builder : public QObject
{
    Q_OBJECT
public:
    virtual void Buildkino(QString name, QString year, QString zhanr, QString time, QString places) const = 0; //метод для создания инф-и о фильме
    virtual void Buildclient(QString sname, QString name, QString pname, QString num, QString mail) const = 0; //метод для создания инф-и о клиенте
    virtual void Buildticket(QString film, QString sname, QString name, QString pl) const = 0; //метод для создания инф-ии о билете
    virtual product* GetRes() {return nullptr;} //метод, возвращающий готовый объект с нужной инф-ей
};

#endif // BUILDER_H
