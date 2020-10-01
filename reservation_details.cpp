#include "reservation_details.h"
#include "ui_reservation_details.h"

QString Fromto;
reservation_details::reservation_details(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservation_details)
{
    ui->setupUi(this);
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");
    db.open();
    QSqlQuery fetch, remove;
    fetch.exec("select*from temp");
    while(fetch.next()){
        Fromto = fetch.value(0).toString();
    }
    remove.exec("delete from temp");
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
    reload();
}

void reservation_details::reload(){
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");
    db.open();
    QSqlQuery display_details;
    display_details.exec("select*from "+Fromto+"info order by Seat_Number");
    QSqlQueryModel *m = new QSqlQueryModel;
    m->setQuery(display_details);
    ui->table_view->setModel(m);
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}

reservation_details::~reservation_details()
{
    delete ui;
}

void reservation_details::on_reload_btn_clicked()
{
    reload();
}
