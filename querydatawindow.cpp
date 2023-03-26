#include "querydatawindow.h"
#include "ui_querydatawindow.h"
#include <QMessageBox>
#include <QSqlQueryModel>

QueryDataWindow::QueryDataWindow(Database *database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryDataWindow),
    m_database(database)
{
    ui->setupUi(this);
}

QueryDataWindow::~QueryDataWindow()
{
    delete ui;
}

void QueryDataWindow::on_executeQueryButton_clicked()
{
    QString queryStr = ui->queryLineEdit->text();

    if (queryStr.isEmpty()) {
        QMessageBox::warning(this, "Execute Query", "Please input a query.");
        return;
    }

    QSqlQueryModel *model = m_database->queryData(queryStr);
    if (model) {
        ui->resultTableView->setModel(model);
    } else {
        QMessageBox::warning(this, "Execute Query", "Failed to execute query.");
    }
}
