#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QVector>
#include "company.h"
class Entity : public QObject
{
    Q_OBJECT
    Q_ENUMS(dispArguments)
public:
    enum class dispArguments {
        companyName = 0,
        companyCountry = 1,
//        companyOwner = 2,
        sizeArguments = 2 //3
    };
    explicit Entity(QObject *parent = nullptr);
    ~Entity();

    QVector<QStringList>& parametersList();
    QStringList getHeader();
    bool removeObject(int index);
    bool addNewObject();
    QString getObject(int row, int column);
    int getCountObjects();
    bool setObject(int row, int column, QString value);
signals:

public slots:
private:
    QVector<QStringList> parametersList_;
    void fillParameters();
    void fillObjects();
    QList<Company*> companyList_;

};

#endif // ENTITY_H
