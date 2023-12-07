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
    // 获取用户输入的查询语句
    QString queryStr = ui->queryLineEdit->text();

    // 如果查询语句为空，则弹出警告对话框并返回
    if (queryStr.isEmpty()) {
        QMessageBox::warning(this, "Execute Query", "Please input a query.");
        return;
    }

    // 调用数据库对象的queryData函数来执行查询，获取查询结果数据
    QList<QMap<QString, QVariant>> data = m_database->queryData(queryStr);

    // 如果查询结果不为空，则将查询结果数据传递给自定义表格模型对象，并将其设置为表格视图的模型
    if (!data.isEmpty()) {
        CustomTableModel *model = new CustomTableModel(data, this);
        ui->resultTableView->setModel(model);
    } else {
        QMessageBox::warning(this, "Execute Query", "Failed to execute query.");
    }
}

/*假设有一个名为 student 的表，其中有三个列，分别为 id（整数类型）、name（字符串类型）和 age（整数类型）。

在该界面的输入框中，需要按照以下格式输入查询语句：

SELECT 语句：在“Query”输入框中输入 SELECT 语句，例如“SELECT * FROM student”或“SELECT id, name FROM student WHERE age > 18”。
注意，在输入 SELECT 语句时，需要按照 SQL 语法规范来输入。在本例中，第一个查询语句表示查询 student 表中的所有列，第二个查询语句表示查询 student 表中的 id 和 name 两列，且 age 大于 18。

输入完毕后，点击“Execute Query”按钮，程序会将输入的查询语句传递给数据库对象的 queryData 函数进行处理。如果执行查询成功，则会将查询结果显示在表格视图中；否则会弹出一个警告框，显示“Failed to execute query.”。*/
