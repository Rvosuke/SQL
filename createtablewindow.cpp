#include "createtablewindow.h"
#include "ui_createtablewindow.h"

CreateTableWindow::CreateTableWindow(Database *database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateTableWindow),
    m_database(database)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::Window);
    connect(ui->confirmButton, &QPushButton::clicked, this, &CreateTableWindow::on_createTableButton_clicked);
}

CreateTableWindow::~CreateTableWindow()
{
    delete ui;
}

void CreateTableWindow::on_createTableButton_clicked()
{
    QString tableName = ui->tableNameLineEdit->text();
    QString columnsDefinition = ui->columnsDefinitionLineEdit->text();

    if (tableName.isEmpty() || columnsDefinition.isEmpty()) {
        QMessageBox::warning(this, "Create Table", "Please fill in both table name and columns definition.");
        return;
    }

    QMap<QString, QString> columns;
    QStringList columnDefs = columnsDefinition.split(",", Qt::SkipEmptyParts);
    for (const QString& columnDef : columnDefs) {
        QStringList parts = columnDef.split(" ", Qt::SkipEmptyParts);
        if (parts.size() != 2) {
            QMessageBox::warning(this, "Create Table", "Invalid columns definition.");
            return;
        }
        columns.insert(parts[0].trimmed(), parts[1].trimmed());
    }

    if (m_database->createTable(tableName, columns)) {
        QMessageBox::information(this, "Create Table", "Table created successfully!");
    } else {
        QMessageBox::warning(this, "Create Table", "Failed to create table.");
    }
}
