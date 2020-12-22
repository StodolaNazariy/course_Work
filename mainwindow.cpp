#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <musicobject.h>
#include <QPixmap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(927,752);
    QPixmap pix(":/img/Sheet-Music-Icon.png");
    this->setWindowIcon(pix);
    db = new DataBase();
    db->connectToDataBase();
    line_E[0]=ui->LE_songname;
    line_E[1]=ui->LE_singername;
    line_E[2]=ui->LE_singersfeat;
    line_E[3]=ui->LE_songlanguage;
    line_E[4]=ui->LE_releaseyear;
    this->setupModel(TABLE,
                     QStringList() << tr("id")
                                   << tr("Назва пісні")
                                   << tr("Ім'я виконавця")
                                   << tr("Доп. учасники")
                                   << tr("Мова написання")
                                   << tr("Рік релізу")
               );
    this->setupModel_createUI();
    QSqlQuery querry_select_columns;
    querry_select_columns.exec("SELECT songname, singername, singersfeat, songlanguage, releasedate FROM TableExample");
     if(querry_select_columns.isActive()){
        int i=0;
        while(querry_select_columns.next()){
            musicObject obj;
            obj.set_song_name(querry_select_columns.value(0).toString());
            obj.set_singer_name(querry_select_columns.value(1).toString());
            obj.set_singers_feat(querry_select_columns.value(2).toString());
            obj.set_song_language(querry_select_columns.value(3).toString());
            obj.set_song_releasedate(querry_select_columns.value(4).toString());
            i++;
            music_List.push_back(obj);
        }
    }
     ui->statusbar->showMessage("Програма готова до роботи!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupModel(const QString &tableName, const QStringList &headers)
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    model->setSort(0,Qt::AscendingOrder);
}

void MainWindow::setupModel_createUI()
{
    this->setupModel(TABLE,
                     QStringList() << tr("id")
                                   << tr("Назва пісні")
                                   << tr("Ім'я виконавця")
                                   << tr("Доп. учасники")
                                   << tr("Мова написання")
                                   << tr("Рік релізу")
               );
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    model->select();
}

bool MainWindow::check_Input()
{
    if(line_E[0]->text().isEmpty() || line_E[1]->text().isEmpty()){
        QMessageBox::warning(this,"Warning","Поля `Назва пісня` та "
                                            "`Ім'я автора` обов'язкові для заповнення!"
                                            " Всі інші поля не обов'язкові");
        return 0;
    }
    return 1;
}

void MainWindow::create_MusicObject()
{
    musicObject obj;
    obj.set_song_name(line_E[0]->text());
    obj.set_singer_name(line_E[1]->text());
    obj.set_singers_feat(line_E[2]->text());
    obj.set_song_language(line_E[3]->text());
    obj.set_song_releasedate(line_E[4]->text());
    this->music_List.push_back(obj);
    db->inserIntoTable(music_List, music_List.size()-1);
    setupModel_createUI();
    ui->statusbar->showMessage("Додано композицію!");
    for(int i=0;i<5;i++){line_E[i]->text().clear();}
}

void MainWindow::fill_Empty_Lines()
{
    for(int i=2;i<5;i++){
        if(line_E[i]->text().isEmpty()){
            line_E[i]->setText("-");
        }
    }
}

void MainWindow::query_del_Table()
{
    QSqlQuery query;
    query.prepare("DELETE FROM " TABLE "");
    query.exec();
}

bool MainWindow::questionQMB(QString message)
{
    ui->statusbar->showMessage("...");
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Question", message,
                                    QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        return 1;
    }
    else{
        return 0;
    }
}

void MainWindow::on_pb_addMusic_clicked()
{
    if((line_E[4]->text().toInt()<=2021 && line_E[4]->text().toInt()>1900)
            || line_E[4]->text().isEmpty()){
    if(check_Input()){
        this->fill_Empty_Lines();
        this->create_MusicObject();
    }
    for(int i=0;i<5;i++){
        line_E[i]->clear();
        }
    }
    else{
        QMessageBox::warning(this,"Попередження","Некоректна дата!");
    }
}

void MainWindow::on_pb_clearGuide_clicked()
{
    if(questionQMB("Дійсно очистити?")){
        this->query_del_Table();
        setupModel_createUI();
    }
    music_List.clear();
    ui->statusbar->showMessage("Плейлист очищено!");
}

void MainWindow::on_pb_Exit_clicked()
{
    ui->statusbar->showMessage("...");
    if(questionQMB("Вийти?")){
        this->close();
    }
}

void MainWindow::on_pb_sortGuide_clicked()
{
    sort_Obj.sort_by(music_List, ui->cb_entersort->currentIndex());
    this->query_del_Table();
    for(int i=0;i<music_List.size();i++){
        db->inserIntoTable(music_List, i);
    }
    setupModel_createUI();
    ui->statusbar->showMessage("Плейлист відсортовано!");
}

void MainWindow::on_pb_delElement_clicked()
{
    if(!ui->LE_delement->text().isEmpty()){
        del_Element=ui->LE_delement->text().toInt();
        if(del_Element >0 && del_Element<music_List.size()+1){
         for(int i=0;i<=music_List.size();i++){
            if(i==del_Element){
                music_List.erase(music_List.begin()+i-1);
                ui->statusbar->showMessage("Видалено композицію");
                this->query_del_Table();
                for(int i=0;i<music_List.size();i++){
                        db->inserIntoTable(music_List, i);
                }
                setupModel_createUI();
            }
            }
        }
        else{
            QMessageBox::warning(this,"Попередження","Заданого значення немає в таблиці!");
        }
    }
    else{
        QMessageBox::warning(this,"Попередження","Поле пусте");
    }
    ui->LE_delement->clear();
}
