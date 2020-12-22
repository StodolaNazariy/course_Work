#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSqlTableModel>
#include "database.h"
#include <QLineEdit>
#include <musicobject.h>
#include <sortmusic.h>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pb_addMusic_clicked();

    void on_pb_clearGuide_clicked();

    void on_pb_Exit_clicked();

    void on_pb_sortGuide_clicked();

    void on_pb_delElement_clicked();

private:
    Ui::MainWindow  *ui;
    DataBase        *db;
    QSqlTableModel  *model;
    QLineEdit *line_E[5];
    QVector<musicObject> music_List;
    sortMusic sort_Obj;
    int del_Element;

private:
    void setupModel(const QString &tableName, const QStringList &headers);
    bool questionQMB(QString message);
    void setupModel_createUI();
    bool check_Input();
    void create_MusicObject();
    void fill_Empty_Lines();
    void query_del_Table();
};
#endif // MAINWINDOW_H
