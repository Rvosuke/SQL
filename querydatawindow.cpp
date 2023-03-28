#include "querydatawindow.h"
#include "ui_querydatawindow.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include "customtablemodel.h"

QueryDataWindow::QueryDataWindow(Database *database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryDataWindow),
    m_database(database)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::Window);
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

    QList<QMap<QString, QVariant>> data = m_database->queryData(queryStr);
    if (!data.isEmpty()) {
        CustomTableModel *model = new CustomTableModel(data, this);
        ui->resultTableView->setModel(model);
    } else {
        QMessageBox::warning(this, "Execute Query", "Failed to execute query.");
    }
}
