#include "country.h"
Country::Country()
{
    name_ = "";

}

QString Country::name() const
{
    return name_;
}

void Country::setName(const QString &name)
{
    name_ = name;
}
