#ifndef IMPORTERTTOHTML_H
#define IMPORTERTTOHTML_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include "company.h"

class ImportertToHtml
{
public:
    ImportertToHtml();
    QFile* file_;

    bool openFile(QString fileName);
    bool closeFile();
    bool createTable(QString name, QStringList &headerTable, QVector<QVector<QString> > &parameters);

private:
    void creatHeadStyle();
    QTextStream stream;
};

#endif // IMPORTERTTOHTML_H
