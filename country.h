#ifndef COUNTRY_H
#define COUNTRY_H
#include <QString>

class Country
{
public:
    explicit Country(QString name) : name_(name){}
    Country();
    QString name() const;

    void setName(const QString &name);

private:
    QString name_;
};

#endif // COUNTRY_H
