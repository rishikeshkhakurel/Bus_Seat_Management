#include "landing_page3.h"
#include "ui_landing_page3.h"
#include "bus_seat_management_system.h"
#include "password_change.h"

landing_page3::landing_page3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::landing_page3)
{
    ui->setupUi(this);
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");

    QSqlQuery *qry=new QSqlQuery(QSqlDatabase::database());

    qry->prepare("select distinct froom from fromto");
    qry->exec();
    modal->setQuery(*qry);
    ui->From->setModel(modal);
    db.close();
}

void landing_page3::on_From_activated(const QString &arg1)
{
    QSqlDatabase db;
    QSqlQueryModel *modaal=new QSqlQueryModel();
    QSqlDatabase dbb;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");
    QSqlQuery *qrry=new QSqlQuery(QSqlDatabase::database());
    qrry->prepare("select too from fromto where froom = '"+arg1+"'");
    qrry->exec();
    modaal->setQuery(*qrry);
    ui->To->setModel(modaal);
    db.close();
}

landing_page3::~landing_page3()
{
    delete ui;
}

void landing_page3::on_see_seat_clicked()
{
    QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");
        db.open();

        QString from= ui->From->currentText();
        QString to=ui->To->currentText();
        QString fromto= from+to;

        QSqlQuery query1,query2;

        query1.exec("create table tempp (name text)");
        query2.prepare("insert into tempp (name)" "values(:fromto)");
        query2.bindValue(":fromto",fromto);
        query2.exec();

        db.close();


        landing_page landing_page;
        landing_page.setModal(true);
        landing_page.exec();

}

void landing_page3::on_pushButton_clicked()
{
    ui->Phone_num->setStyleSheet("");
    ui->seat_num->setStyleSheet("");
    ui->tick_name->setStyleSheet("");
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");

    QString tick_name = ui->tick_name->text();
    QString Phone_num = ui->Phone_num->text();
    int seat_num = ui->seat_num->text().toInt();
    QString From= ui->From->currentText();
    QString To= ui->To->currentText();
    QString info="info";
    QString FromToinfo= From+To+info;
    QString FromTo= From+To;
    int resseat;

    if(!db.open()){
        QMessageBox::information(this,"Error","Database not found");
    }

        QSqlQuery query,query1,query2;
        query.prepare("insert into "+FromToinfo+" (Name, Phone_Number, Seat_Number)" "values(:tick_name, :Phone_num, :seat_num)");
        query.bindValue(":seat_num",seat_num);
        query.bindValue(":tick_name",tick_name);
        query.bindValue(":Phone_num",Phone_num);
        query1.prepare("update "+FromTo+" set is_Reserved = 1 where Seat_Number=:seat_num");
        query1.bindValue(":seat_num", seat_num);
        query2.prepare("select is_Reserved from "+FromTo+" where Seat_Number= :seat_num");
        query2.bindValue(":seat_num", seat_num);
        query2.exec();

        while (query2.next()) {
                resseat = query2.value(0).toInt();
            }
        if(!resseat){
            int details_are_valid = 0;
            if(Phone_num.length()==10){
                if(tick_name != ""){
                    if(1 <= seat_num && seat_num <= 31){
                        details_are_valid = 1;
                    }
                    else{
                        QMessageBox::information(this, "Error", "Please select a valid seat number.\nYou can view seat layout by clicking the view seat button.");
                        ui->seat_num->setStyleSheet("border: 1px solid red");
                        return;
                    }
                }
                else{
                    QMessageBox::information(this, "Error", "Passenger's name cannot be left empty");
                    ui->tick_name->setStyleSheet("border: 1px solid red");
                    return;
                }
            }
            else{
                QMessageBox::information(this, "Error", "The phone number you entered doesn't seem quite right.\nPlease re-check it and try again.");
                ui->Phone_num->setStyleSheet("border: 1px solid red");
                return;
            }
            if(details_are_valid){
                query.exec();
                query1.exec();
                QMessageBox::information(this,"Sucessfull","Your Ticket is booked sucessfully");
                ui->tick_name->clear();
                ui->Phone_num->clear();
                ui->seat_num->clear();
            }
            else
                QMessageBox::information(this, "Error", "Please re-check the details you entered and try again.");
            }

        else{
            QMessageBox::information(this,"Sorry","The seat is already booked");
        }
db.close();
db.removeDatabase(QSqlDatabase::defaultConnection);
}
void landing_page3::on_back_clicked()
{
    this->close();
    Bus_Seat_Management_System *mainWindow = new Bus_Seat_Management_System();
    mainWindow->show();

}


void landing_page3::on_change_ps_btn_clicked()
{
    password_change password_change;
    password_change.setModal(true);
    password_change.exec();
}

