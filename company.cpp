#include "company.h"

Company::Company(QUuid Uuid, QString nameCompany, Country* country, QObject *parent) :
    QObject(parent),
    uid_(Uuid),
    nameCompany_(nameCompany),
    country_(country)
{
}

Company::~Company()
{
    delete country_;
}


QString Company::nameCompany() const
{
    return nameCompany_;
}

Country *Company::country() const
{
    return country_;
}

void Company::setNameCompany(const QString &nameCompany)
{
    nameCompany_ = nameCompany;
}

