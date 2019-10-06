#include "importerttohtml.h"

ImportertToHtml::ImportertToHtml()
{

}

bool ImportertToHtml::openFile(QString fileName)
{
    if(fileName.indexOf('.') == -1)
        fileName += ".html";
    else if(fileName.mid(fileName.indexOf('.')) != ".html")
        qDebug() << fileName << "is not html file. Please rename fileName";
    file_ = new QFile(fileName);
    if(!file_->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writting";
        return false;
    }
    QTextStream stream(file_);
    stream << "<html>" << '\n';
    return true;
}

bool ImportertToHtml::closeFile()
{
    if(file_ == nullptr)
        return false;
    QTextStream stream(file_);
    stream << "</html>" << '\n';
    file_->close();
    return true;
}

bool ImportertToHtml::createTable(QString name, QStringList& headerTable,QVector<QVector<QString>>& parameters)
{
    creatHeadStyle();
    QTextStream stream(file_);
    stream << "<body>";
    stream << "<h2>" << name << "</h2>" << '\n';
    stream << "<table>" << '\n';

    stream << "<tr>" << '\n';
    for(int numHead = 0; numHead < headerTable.size(); ++numHead)
        stream << "<th>" << headerTable.at(numHead) <<"</th>"<< '\n';
    stream << "</tr>" << '\n';
    for(int row = 0; row < parameters.size(); ++row)
    {
        stream << "<tr>";
        for(int column = 0; column < parameters[row].size(); ++column)
        {
            stream << "<td>";
            stream << parameters[row][column];
            stream << "</td>" << '\n';
        }

        stream << "</tr>" << '\n';
    }
    stream << "</table>" << '\n';
    stream << "</body>" << '\n';
    return true;
}

void ImportertToHtml::creatHeadStyle()
{
    QTextStream stream(file_);
    stream << "<head>" << '\n';
    stream << "<style>" << '\n';
    QString styleTable;
    styleTable = "table {"
                 "font-family: arial, sans-serif;"
                 "border-collapse: collapse;"
                 "width: 100%;} td, th {"
                 "border: 1px solid #dddddd;"
                 "text-align: left;"
                 "padding: 8px;}"
                 "tr:nth-child(even) {"
                 " background-color: #dddddd; }";
    stream << styleTable << '\n';

    stream << "</style>" << '\n';
    stream << "</head>" << '\n';
}



