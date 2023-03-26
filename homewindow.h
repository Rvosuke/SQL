#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QWidget>
#include "database.h"
#include "createtablewindow.h"
#include "insertdatawindow.h"
#include "updatedatawindow.h"
#include "deletedatawindow.h"
#include "querydatawindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {class HomeWindow;}
QT_END_NAMESPACE

class HomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWindow(Database *database, QWidget *parent = nullptr);
    ~HomeWindow();
signals:
    void openInsertDataWindow();
    void openUpdateDataWindow();
    void openDeleteDataWindow();
    void openQueryDataWindow();
private slots:
    void on_createTableButton_clicked();
    void on_insertDataButton_clicked();
    void on_updateDataButton_clicked();
    void on_deleteDataButton_clicked();
    void on_queryDataButton_clicked();

private:
    Ui::HomeWindow *ui;
    Database *m_database;
};

#endif // HOMEWINDOW_H
