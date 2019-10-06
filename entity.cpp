#include "entity.h"

Entity::Entity(QObject *parent) : QObject(parent)
{
    fillParameters();
    fillObjects();
}

Entity::~Entity()
{
    qDeleteAll(companyList_);
    companyList_.clear();
}

QVector<QStringList> &Entity::parametersList()
{
    return parametersList_;
}

QStringList Entity::getHeader()
{
    QStringList list;
    for(int index = 0; index < static_cast<int>(dispArguments::sizeArguments); ++index)
        switch (static_cast<dispArguments>(index)) {
        case dispArguments::companyName:
            list.push_back("CompanyName");
        break;
        case dispArguments::companyCountry:
            list.push_back("CompanyCountry");
        break;
//        case dispArguments::companyOwner:
//            list.push_back("Owner");
//        break;
        default: break;
        }
    return list;
}

bool Entity::removeObject(int index)
{
    if(index < 0 || index >= companyList_.size())
        return false;
    delete companyList_.at(index);
    companyList_.removeAt(index);
    return true;
}

bool Entity::addNewObject()
{
    companyList_.push_back(new Company(QUuid::createUuid(), parametersList_[static_cast<int>(dispArguments::companyName)].first(),
                           new Country(parametersList_[static_cast<int>(dispArguments::companyCountry)].first())/*,
            parametersList_[static_cast<int>(dispArguments::companyOwner)].first()*/));
    return true;
}

void Entity::fillParameters()
{
    for(int parameter = 0; parameter < static_cast<int>(dispArguments::sizeArguments); ++parameter)
        parametersList_.push_back(QStringList());

    parametersList_[static_cast<int>(dispArguments::companyName)].push_back("Татнефть");
    parametersList_[static_cast<int>(dispArguments::companyName)].push_back("ADCO");
    parametersList_[static_cast<int>(dispArguments::companyName)].push_back("Agip KCO");

    parametersList_[static_cast<int>(dispArguments::companyCountry)].push_back("Россия");
    parametersList_[static_cast<int>(dispArguments::companyCountry)].push_back("Italy");
    parametersList_[static_cast<int>(dispArguments::companyCountry)].push_back("Canada");

//    parametersList_[static_cast<int>(dispArguments::companyOwner)].push_back("Вася");
//    parametersList_[static_cast<int>(dispArguments::companyOwner)].push_back("Петя");
//    parametersList_[static_cast<int>(dispArguments::companyOwner)].push_back("Ваня");

}

void Entity::fillObjects()
{
    if(parametersList_[static_cast<int>(dispArguments::companyName)].isEmpty() ||
            parametersList_[static_cast<int>(dispArguments::companyCountry)].isEmpty())
        return;

    int countObjects = 3; // количество строк (объектов в таблице) по умолчанию
    for(int num = 0; num < countObjects; ++num)
        companyList_.push_back(new Company(QUuid::createUuid(), parametersList_[static_cast<int>(dispArguments::companyName)].first(),
                           new Country(parametersList_[static_cast<int>(dispArguments::companyCountry)].first())/*,
                parametersList_[static_cast<int>(dispArguments::companyOwner)].first()*/));
}

QString Entity::getObject(int row, int column)
{
    if(row < 0 || row >= companyList_.size())
        return QString();
    switch (static_cast<Entity::dispArguments>(column)) {
    case Entity::dispArguments::companyName:
        return companyList_.at(row)->nameCompany();
    case Entity::dispArguments::companyCountry:
        return companyList_.at(row)->country()->name();
//    case Entity::dispArguments::companyOwner:
//        return companyList_.at(row)->Owner();
    default: break;
    }
    return QString();
}

int Entity::getCountObjects()
{
    return companyList_.size();
}

bool Entity::setObject(int row, int column, QString value)
{
    Company* selectedCompany = companyList_.at(row);
    switch (static_cast<Entity::dispArguments>(column)) {
    case Entity::dispArguments::companyName:
        selectedCompany->setNameCompany(value);
        return true;
    case Entity::dispArguments::companyCountry:
        selectedCompany->country()->setName(value);
        return true;
//    case Entity::dispArguments::companyOwner:
//        selectedCompany->setOwner(value);
//        return true;
    default:
        return false;
    }
    return false;
}


