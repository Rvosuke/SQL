#include "insertdatawindow.h"
#include "ui_insertdatawindow.h"

InsertDataWindow::InsertDataWindow(Database *database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InsertDataWindow),
    m_database(database)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::Window);
}

InsertDataWindow::~InsertDataWindow()
{
    delete ui;
}

void InsertDataWindow::on_insertDataButton_clicked()
{
    // 获取用户输入的表名和数据
    QString tableName = ui->tableNameLineEdit->text();
    QString data = ui->dataLineEdit->text();

    // 如果表名或数据为空，则弹出警告对话框并返回
    if (tableName.isEmpty() || data.isEmpty()) {
        QMessageBox::warning(this, "Insert Data", "Please fill in both table name and data.");
        return;
    }

    // 这里假设数据使用逗号分隔。实际上，您可能需要使用更复杂的格式，例如 JSON 或 CSV。
    QStringList dataList = data.split(",", Qt::SkipEmptyParts);

    // 创建一个 QMap 以存储数据
    QMap<QString, QVariant> dataMap;
    for (int i = 0; i < dataList.count(); ++i) {
        // 假设每个键值对使用等号分隔
        QStringList keyValue = dataList[i].split("=");
        if (keyValue.count() == 2) {
            dataMap[keyValue[0]] = keyValue[1];
        }
    }

    // 调用数据库对象的insertData函数来插入数据，如果成功则弹出信息对话框，否则弹出警告对话框
    if (m_database->insertData(tableName, dataMap)) {
        QMessageBox::information(this, "Insert Data", "Data inserted successfully!");
    } else {
        QMessageBox::warning(this, "Insert Data", "Failed to insert data.");
    }
}

/*假设有一个名为 student 的表，其中有三个列，分别为 id（整数类型）、name（字符串类型）和 age（整数类型）。

在该界面的输入框中，需要按照以下格式输入：

表名：在“Table Name”输入框中输入表名，例如“student”。
数据：在“Data”输入框中输入要插入的数据，例如“id=1,name=John,age=20”。
注意，在输入数据时，需要按照“列名=值”的格式输入，不同数据项之间使用逗号隔开。
对于字符串类型的值，需要使用引号将其括起来。
在本例中，name 的值是一个字符串类型，因此需要将其用引号括起来，例如“id=1,name='John',age=20”。

输入完毕后，点击“Insert Data”按钮，程序会将输入的表名和数据传递给数据库对象的 insertData 函数进行处理。
如果插入数据成功，则会弹出一个信息对话框，显示“Data inserted successfully!”；否则会弹出一个警告框，显示“Failed to insert data.”。*/
