#include "bus_seat_management_system.h"
#include "ui_bus_seat_management_system.h"
#include "landing_page3.h"
#include"landing_page2.h"
#include"owner_page.h"


Bus_Seat_Management_System::Bus_Seat_Management_System(QWidget *parent)

    : QMainWindow(parent)
    , ui(new Ui::Bus_Seat_Management_System)
{

    ui->setupUi(this);

}

Bus_Seat_Management_System::~Bus_Seat_Management_System()
{
    delete ui;
}


void Bus_Seat_Management_System::on_log_in_clicked()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");

    QString email = ui->bt_email->text();
    QString password = ui->pass->text();

    if(!db.open()){
        QMessageBox::information(this,"Error","Database not found");
    }

        QSqlQuery query;

        if(query.exec("select * from login_info where email='"+email+"' and password='"+password+"'")){
            int count=0;
            if(email=="admin" && password=="admin"){
                count=2;
            }

            if(count==2){
                db.close();
                this->close();
                owner_page owner_page;
                owner_page.setModal(true);
                owner_page.exec();

            }

            while(query.next()){
                count++;
            }


                if(count==1){
                    db.close();
                    this->close();
                    landing_page3 landing_page3;
                    landing_page3.setModal(true);
                    landing_page3.exec();
                }

                if(count>2)
                    QMessageBox::information(this,"unsucessfull login","wrong username or password");
                ui->pass->clear();

                if(count<1)
                    QMessageBox::information(this,"unsucessfull login","wrong username or password");
                ui->pass->clear();

            }

        else{
            qDebug() << query.lastError().text();
        }





db.close();
db.removeDatabase(QSqlDatabase::defaultConnection);

}

void Bus_Seat_Management_System::on_sign_up_clicked()
{
    this->hide();

    landing_page2 landing_page2;
    landing_page2.setModal(true);
    landing_page2.exec();



}
