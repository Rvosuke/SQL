#include "homewindow.h"
#include "ui_homewindow.h"
#include "createtablewindow.h"
#include "insertdatawindow.h"
#include "updatedatawindow.h"
#include "deletedatawindow.h"
#include "querydatawindow.h"

HomeWindow::HomeWindow(Database *database, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWindow),
    m_database(database)
{
    ui->setupUi(this);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::on_createTableButton_clicked()
{
    CreateTableWindow *createTableWindow = new CreateTableWindow(m_database, this);
    createTableWindow->setAttribute(Qt::WA_DeleteOnClose);
    createTableWindow->show();
}

void HomeWindow::on_insertDataButton_clicked()
{
    emit openInsertDataWindow();
    InsertDataWindow *insertDataWindow = new InsertDataWindow(m_database, this);
    insertDataWindow->setAttribute(Qt::WA_DeleteOnClose);
    insertDataWindow->show();
}

void HomeWindow::on_updateDataButton_clicked()
{
    emit openUpdateDataWindow();
    UpdateDataWindow *updateDataWindow = new UpdateDataWindow(m_database, this);
    updateDataWindow->setAttribute(Qt::WA_DeleteOnClose);
    updateDataWindow->show();
}

void HomeWindow::on_deleteDataButton_clicked()
{
    emit openDeleteDataWindow();
    DeleteDataWindow *deleteDataWindow = new DeleteDataWindow(m_database, this);
    deleteDataWindow->setAttribute(Qt::WA_DeleteOnClose);
    deleteDataWindow->show();
}

void HomeWindow::on_queryDataButton_clicked()
{
    emit openQueryDataWindow();
    QueryDataWindow *queryDataWindow = new QueryDataWindow(m_database, this);
    queryDataWindow->setAttribute(Qt::WA_DeleteOnClose);
    queryDataWindow->show();
}
