#ifndef DELETEDATAWINDOW_H
#define DELETEDATAWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class DeleteDataWindow;
}

class DeleteDataWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteDataWindow(Database *database, QWidget *parent = nullptr);
    ~DeleteDataWindow();

private slots:
    void on_deleteDataButton_clicked();

private:
    Ui::DeleteDataWindow *ui;
    Database *m_database;
};

#endif // DELETEDATAWINDOW_H
