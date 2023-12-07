#ifndef QUERYDATAWINDOW_H
#define QUERYDATAWINDOW_H

#include <QWidget>
#include "database.h"

namespace Ui {
class QueryDataWindow;
}

class QueryDataWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QueryDataWindow(Database *database, QWidget *parent = nullptr);
    ~QueryDataWindow();

private slots:
    void on_executeQueryButton_clicked();

private:
    Ui::QueryDataWindow *ui;
    Database *m_database;
};

#endif // QUERYDATAWINDOW_H
