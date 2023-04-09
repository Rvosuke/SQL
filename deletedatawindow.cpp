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
    // 获取用户输入的表名和删除条件
    QString tableName = ui->tableNameLineEdit->text();
    QString condition = ui->conditionLineEdit->text();

    // 如果表名或删除条件为空，则弹出警告对话框并返回
    if (tableName.isEmpty() || condition.isEmpty()) {
        QMessageBox::warning(this, "Delete Data", "Please fill in both table name and condition.");
        return;
    }

    // 调用数据库对象的deleteData函数来删除数据，如果成功则弹出信息对话框，否则弹出警告对话框
    if (m_database->deleteData(tableName, condition)) {
        QMessageBox::information(this, "Delete Data", "Data deleted successfully!");
    } else {
        QMessageBox::warning(this, "Delete Data", "Failed to delete data.");
    }
}

/*假设要删除一个名为 student 的表中所有年龄为 20 岁的学生记录。

在该界面的输入框中，需要按照以下格式输入：

表名：在“Table Name”输入框中输入表名，例如“student”。
删除条件：在“Condition”输入框中输入删除条件，例如“age = 20”。
注意，在输入删除条件时，需要按照 SQL 语法规范来输入。
在本例中，age 是 student 表中的一个列名，因此需要将其放在左侧；= 是比较运算符，用于判断两个值是否相等；20 是需要删除的学生的年龄，因此需要将其放在右侧。

输入完毕后，点击“Delete Data”按钮，程序会将输入的表名和删除条件传递给数据库对象的 deleteData 函数进行处理。
如果删除成功，则会弹出一个信息框，显示“Data deleted successfully!”；否则会弹出一个警告框，显示“Failed to delete data.”。*/
