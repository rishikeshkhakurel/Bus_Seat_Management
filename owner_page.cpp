#include "owner_page.h"
#include "ui_owner_page.h"
#include "owner_seats.h"
#include "reservation_details.h"
#include "bus_seat_management_system.h"

owner_page::owner_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::owner_page)
{
    ui->setupUi(this);
}

owner_page::~owner_page()
{
    delete ui;
}
void owner_page::validate(QString action){
    QString from = ui->from->text().toLower();
    QString to = ui->to->text().toLower();
    int route_exists = 0;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");
    db.open();
    QSqlQuery validate;
    validate.exec("select*from fromto where froom = '"+from+"' and too = '"+to+"'");
    while(validate.next()){
        route_exists = 1;
    }
    if(route_exists){
        QSqlQuery create, insert_val;
        insert_val.exec("insert into temp(from_to) values('"+from+to+"')");
        if(action =="edit"){
            owner_seats next_page;
            next_page.setModal(true);
            next_page.exec();
        }
        else if(action == "view"){
            reservation_details next_page;
            next_page.setModal(true);
            next_page.exec();
        }
        ui->from->clear();
        ui->to->clear();
    }
    else
        QMessageBox::information(this, "Error", "Please enter a valid route");
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);

}
void owner_page::on_view_reservation_btn_clicked()
{
    validate("view");
}

void owner_page::on_edit_reservation_btn_clicked()
{
    validate("edit");
}

void owner_page::on_add_route_btn_clicked()
{
    QString from = ui->from->text().toLower();
    QString to = ui->to->text().toLower();
    int route_exists = 0;
    if(from!="" && to!=""){
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");
        db.open();
        QSqlQuery validate;
        validate.exec("select*from fromto where froom = '"+from+"' and too = '"+to+"'");
        while(validate.next()){
            route_exists = 1;
        }
        if(!route_exists){
            QSqlQuery add_to_list, create_tbl, create_info_tbl;
            add_to_list.exec("insert into fromto(froom, too) values('"+from+"', '"+to+"')");
            create_tbl.exec("create table "+from+to+"(Seat_Number text not null unique, is_Reserved text not null)");
            create_info_tbl.exec("create table "+from+to+"info(Name text not null, Phone_Number text not null, Seat_Number text not null unique)");
            QMessageBox::information(this, "Successful", "Route added successfully!");
            for(int i = 1; i<=31; i++){
                QSqlQuery fill;
                fill.prepare("insert into "+from+to+"(Seat_Number, is_Reserved) values(:val, 0)");
                fill.bindValue(":val", i);
                fill.exec();

            }
        }
        else
            QMessageBox::information(this, "Error", "The route already exists");
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    else
        QMessageBox::information(this, "Error", "Enter the starting place and destination to add a route.");

    ui->from->clear();
    ui->to->clear();
}

void owner_page::on_remove_route_btn_clicked()
{
    int route_exists = 0;
    QString from = ui->from->text().toLower();
    QString to = ui->to->text().toLower();
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");
    db.open();
    QSqlQuery validate;
    validate.exec("select*from fromto where froom = '"+from+"' and too = '"+to+"'");
    while(validate.next()){
        route_exists = 1;
    }
    if(route_exists){
        QSqlQuery remove_from_list, remove_tbl, remove_info_tbl;
        remove_from_list.prepare("delete from fromto where froom = '"+from+"' and too = '"+to+"'");
        remove_tbl.prepare("drop table "+from+to);
        remove_info_tbl.prepare("drop table "+from+to+"info");
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Remove Route?", "Are you sure you want to remove the route?\nThis action is irreversible and all the data related to this route will be lost permanently.", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
            remove_from_list.exec();
            remove_tbl.exec();
            remove_info_tbl.exec();
            QMessageBox::information(this, "Successful", "Route removed successfully");
        }
    }
    else
        QMessageBox::information(this, "Error", "Such route does not exist");

    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
    ui->from->clear();
    ui->to->clear();
}

void owner_page::on_logout_btn_clicked()
{
    this->close();
    Bus_Seat_Management_System *mainWindow = new Bus_Seat_Management_System();
    mainWindow->show();
}
