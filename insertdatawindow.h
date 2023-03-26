#ifndef INSERTDATAWINDOW_H
#define INSERTDATAWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class InsertDataWindow;
}

class InsertDataWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InsertDataWindow(Database *database, QWidget *parent = nullptr);
    ~InsertDataWindow();

private slots:
    void on_insertDataButton_clicked();

private:
    Ui::InsertDataWindow *ui;
    Database *m_database;
};

#endif // INSERTDATAWINDOW_H
