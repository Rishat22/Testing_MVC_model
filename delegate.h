#ifndef DELEGATE_H
#define DELEGATE_H
#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QObject>
#include <QComboBox>
#include <QMouseEvent>
class Delegate : public QItemDelegate
{
    Q_OBJECT
public:
    Delegate(QObject *parent = nullptr);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
signals:
public slots:
private:

};

#endif // DELEGATE_H
