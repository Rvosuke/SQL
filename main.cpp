#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "mainwindow.h"
#include "database.h"
#include "homewindow.h"
#include "insertdatawindow.h"
#include "updatedatawindow.h"
#include "deletedatawindow.h"
#include "querydatawindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "SQL2_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    Database db;

    MainWindow loginWindow(&db);
    loginWindow.show();

    HomeWindow homeWindow(&db);
    InsertDataWindow insertDataWindow(&db);
    UpdateDataWindow updateDataWindow(&db);
    DeleteDataWindow deleteDataWindow(&db);
    QueryDataWindow queryDataWindow(&db);

    // Connect signals and slots for opening windows
    QObject::connect(&loginWindow, &MainWindow::loginSuccess, &homeWindow, &HomeWindow::show);
    QObject::connect(&homeWindow, &HomeWindow::openInsertDataWindow, &insertDataWindow, &InsertDataWindow::show);
    QObject::connect(&homeWindow, &HomeWindow::openUpdateDataWindow, &updateDataWindow, &UpdateDataWindow::show);
    QObject::connect(&homeWindow, &HomeWindow::openDeleteDataWindow, &deleteDataWindow, &DeleteDataWindow::show);
    QObject::connect(&homeWindow, &HomeWindow::openQueryDataWindow, &queryDataWindow, &QueryDataWindow::show);

    return a.exec();
}
