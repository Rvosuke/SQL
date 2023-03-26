#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(Database *database, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_database(database)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString host = ui->hostLineEdit->text();
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString databaseName = ui->databaseNameLineEdit->text();

    if (m_database->connectToDatabase(host, username, password, databaseName)) {
        emit loginSuccess();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Failed", "Failed to connect to the database. Please check your input and try again.");
    }
}
