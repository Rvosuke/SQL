#include "deletedatawindow.h"
#include "ui_deletedatawindow.h"

DeleteDataWindow::DeleteDataWindow(Database *database,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteDataWindow),
    m_database(database)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::Window);
}

DeleteDataWindow::~DeleteDataWindow()
{
    delete ui;
}

void DeleteDataWindow::on_deleteDataButton_clicked()
{
    QString tableName = ui->tableNameLineEdit->text();
    QString condition = ui->conditionLineEdit->text();

    if (tableName.isEmpty() || condition.isEmpty()) {
        QMessageBox::warning(this, "Delete Data", "Please fill in both table name and condition.");
        return;
    }

    if (m_database->deleteData(tableName, condition)) {
        QMessageBox::information(this, "Delete Data", "Data deleted successfully!");
    } else {
        QMessageBox::warning(this, "Delete Data", "Failed to delete data.");
    }
}
