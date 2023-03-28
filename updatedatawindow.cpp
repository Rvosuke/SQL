#include "updatedatawindow.h"
#include "ui_updatedatawindow.h"

UpdateDataWindow::UpdateDataWindow(Database* database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpdateDataWindow),
    m_database(database)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::Window);
}

UpdateDataWindow::~UpdateDataWindow()
{
    delete ui;
}

void UpdateDataWindow::on_updateDataButton_clicked()
{
    QString tableName = ui->tableNameLineEdit->text();
    QString condition = ui->conditionLineEdit->text();
    QString newData = ui->newDataLineEdit->text();

    if (tableName.isEmpty() || condition.isEmpty() || newData.isEmpty()) {
        QMessageBox::warning(this, "Update Data", "Please fill in table name, condition, and new data.");
        return;
    }

    if (m_database->updateData(tableName, condition, newData)) {
        QMessageBox::information(this, "Update Data", "Data updated successfully!");
    } else {
        QMessageBox::warning(this, "Update Data", "Failed to update data.");
    }
}
