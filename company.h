#ifndef COMPANY_H
#define COMPANY_H

#include <QObject>
#include <QUuid>
#include <QList>
#include <QString>
#include "country.h"

class Company : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Owner READ Owner WRITE setOwner)

public:
    explicit Company(QUuid Uuid,QString nameCompany, Country* country, QObject *parent = nullptr);

    explicit Company(QUuid Uuid, QString nameCompany, Country* country,QString owner, QObject *parent = nullptr) :
            QObject(parent),
            uid_(Uuid),
            nameCompany_(nameCompany),
            country_(country),
            m_Owner_(owner)
    {}
    ~Company();
    QString Owner() const
    {
        return m_Owner_;
    }
    QString nameCompany() const;


    Country *country() const;

signals:

public slots:
    void setOwner(const QString &Owner)
    {
        m_Owner_ = Owner;
    }
    void setNameCompany(const QString &nameCompany);
private:
    QUuid uid_;
    QString nameCompany_;
    Country* country_;
    QString m_Owner_;

};

#endif // COMPANY_H
