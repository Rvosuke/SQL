#ifndef UPDATEDATAWINDOW_H
#define UPDATEDATAWINDOW_H

#include <QWidget>
#include "database.h"
#include <QMessageBox>

namespace Ui {
class UpdateDataWindow;
}

class UpdateDataWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UpdateDataWindow(Database *database, QWidget *parent = nullptr);
    ~UpdateDataWindow();

private slots:
    void on_updateDataButton_clicked();

private:
    Ui::UpdateDataWindow *ui;
    Database *m_database;
};

#endif // UPDATEDATAWINDOW_H
