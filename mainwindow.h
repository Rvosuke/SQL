#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(Database *database, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    Database *m_database;

signals:
    void loginSuccess();
};

#endif // MAINWINDOW_H
