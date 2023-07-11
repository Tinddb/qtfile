#ifndef CONCRETEBUILDER_H
#define CONCRETEBUILDER_H

#include "product.h"
#include "builder.h"

class ConcreteBuilder : public builder //реализация конкретного строителя (наследуется от обычного строителя) и реализация
{ //его методов

private:
    product* pr; //пустой объект продукта для дальнейшего заполения

public:
    ConcreteBuilder();
    ~ConcreteBuilder();
    void Reset(); //функция обновления продукта

    //методы строителя для заполения полей продукта нужными данными:
    void Buildkino(QString name, QString year, QString zhanr, QString time, QString places)const override; //инф-я о фильме
    void Buildclient(QString sname, QString name, QString pname, QString num, QString mail) const override; //инф-я о клиенте
    void Buildticket(QString film, QString sname, QString name, QString pl) const override; //инф-ияя о билете
    virtual product * GetRes() override; //метод получения результата


};

#endif // CONCRETEBUILDER_H
