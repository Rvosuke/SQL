#include "insertdatawindow.h"
#include "ui_insertdatawindow.h"

InsertDataWindow::InsertDataWindow(Database *database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InsertDataWindow),
    m_database(database)
{
    ui->setupUi(this);
}

InsertDataWindow::~InsertDataWindow()
{
    delete ui;
}

void InsertDataWindow::on_insertDataButton_clicked()
{
    QString tableName = ui->tableNameLineEdit->text();
    QString data = ui->dataLineEdit->text();

    if (tableName.isEmpty() || data.isEmpty()) {
        QMessageBox::warning(this, "Insert Data", "Please fill in both table name and data.");
        return;
    }

    // 这里假设数据使用逗号分隔。实际上，您可能需要使用更复杂的格式，例如 JSON 或 CSV。
    QStringList dataList = data.split(",", Qt::SkipEmptyParts);

    if (m_database->insertData(tableName, dataList)) {
        QMessageBox::information(this, "Insert Data", "Data inserted successfully!");
    } else {
        QMessageBox::warning(this, "Insert Data", "Failed to insert data.");
    }
}
