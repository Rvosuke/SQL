#ifndef CREATETABLEWINDOW_H
#define CREATETABLEWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class CreateTableWindow;
}

class CreateTableWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CreateTableWindow(Database* database, QWidget *parent = nullptr);
    ~CreateTableWindow();

private slots:
    void on_createTableButton_clicked();

private:
    Ui::CreateTableWindow *ui;
    Database *m_database;
};

#endif // CREATETABLEWINDOW_H
