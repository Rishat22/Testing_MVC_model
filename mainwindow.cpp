#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model_ = new TableModel(this);
    delegateElem_ = new Delegate(this);
    ui->tableView->setModel(model_);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setItemDelegate(delegateElem_);
//    ui->listView->setModel(model_);
    setStyleSheetMainWindow();

}

MainWindow::~MainWindow()
{
    delete model_;
    delete delegateElem_;
    delete ui;
}
auto setGrpColorButton = [](QPushButton* button, QString color){
    QString nameButton = '#' + button->objectName();
    button->setStyleSheet(nameButton + "{background-color:" + color + "; color: #ffffff; border-width: 1px; border-style: solid; "
                                                                       "border-color: rgb(181,181,181); "
                                                                       "font-family: Arial;"
                                                                       "font-size: 12pt; font-weight: 450; border-radius: 1;}"
                                                                       + nameButton + ":pressed{"
                                                                       "background-color: #ffffff;"
                                                                       "color:" + color + ';' +
                                                                       "border-width: 1px; "
                                                                       "border-style: solid; "
                                                                       "border-color: rgb(181,181,181); "
                                                                       "font-family: Arial;"
                                                                       "font-size: 12pt; font-weight: 450; border-radius: 1;}"
                                                                       );};
void MainWindow::setStyleSheetMainWindow()
{
    QString styleObj;
    QString nameObj;
    nameObj = '#' + this->objectName();
    styleObj = nameObj + "{background-color: rgb(238, 238, 238);}";
    this->setStyleSheet(styleObj);
    setGrpColorButton(ui->addButton, "#18799b");
    setGrpColorButton(ui->deleteButton, "#b30000");
}


void MainWindow::on_addButton_clicked()
{
    ui->tableView->model()->insertRows(0,1, QModelIndex());
}

void MainWindow::on_deleteButton_clicked()
{
    QItemSelection selection = ui->tableView->selectionModel()->selection();
    QList<int> removeRows;
    foreach(QModelIndex index, selection.indexes()) {
        if(!removeRows.contains(index.row())) {
            removeRows.append(index.row());
        }
    }

    //loop through all selected rows
    for(int i=0;i<removeRows.count();++i)
    {
        //decrement all rows after the current - as the row-number will change if we remove the current
        for(int j=i;j<removeRows.count();++j) {
            if(removeRows.at(j) > removeRows.at(i)) {
                removeRows[j]--;
            }
        }
        //remove the selected row
        model_->removeRows(removeRows.at(i), 1, QModelIndex());
    }
}
