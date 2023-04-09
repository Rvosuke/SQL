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
    // 获取用户输入的表名和列定义
    QString tableName = ui->tableNameLineEdit->text();
    QString columnsDefinition = ui->columnsDefinitionLineEdit->text();

    // 如果表名或列定义为空，则弹出警告对话框并返回
    if (tableName.isEmpty() || columnsDefinition.isEmpty()) {
        QMessageBox::warning(this, "Create Table", "Please fill in both table name and columns definition.");
        return;
    }

    // 解析列定义，生成列名和类型的键值对
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

    // 调用数据库对象的createTable函数来创建表，如果成功则弹出信息对话框，否则弹出警告对话框
    if (m_database->createTable(tableName, columns)) {
        QMessageBox::information(this, "Create Table", "Table created successfully!");
    } else {
        QMessageBox::warning(this, "Create Table", "Failed to create table.");
    }
}


/*假设有一个关系表需要创建，其中有三个列，分别为 id（整数类型）、name（字符串类型）和 age（整数类型）。

在该界面的输入框中，需要按照以下格式输入：

表名：在“Table Name”输入框中输入表名，例如“student”。
列定义：在“Columns Definition”输入框中输入列定义，例如“id int, name varchar(50), age int”。
注意，在输入列定义时，需要按照“列名 列类型”这样的格式输入，不同列之间用逗号隔开。对于字符串类型，需要在类型后面加上括号，用于指定字符串的长度。
在本例中，name 列的类型是 varchar，其长度为 50。

输入完毕后，点击“Create Table”按钮，程序会将输入的表名和列定义传递给数据库对象的 createTable 函数进行处理。
如果创建表成功，则会弹出一个信息框，显示“Table created successfully!”；否则会弹出一个警告框，显示“Failed to create table.”。*/
