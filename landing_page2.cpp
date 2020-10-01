#include "landing_page2.h"
#include "ui_landing_page2.h"
#include "bus_seat_management_system.h"


Bus_Seat_Management_System *bus;


landing_page2::landing_page2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::landing_page2)
{
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    ui->setupUi(this);

}

landing_page2::~landing_page2()
{
    delete ui;
}

void landing_page2::on_register_2_clicked()
{
    ui->bt_email->setStyleSheet("");
    ui->name->setStyleSheet("");
    ui->pass->setStyleSheet("");
    ui->phnum->setStyleSheet("");
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");

    QString email = ui->bt_email->text();
    QString password = ui->pass->text();
    QString phnum = ui->phnum->text();
    QString name = ui->name->text();

    if(!db.open()){
        QMessageBox::information(this,"Error","Database not found");
    }

    if(name != "" && phnum != "" && email != "" && password != ""){
        int e =0, p = 0, ph = 0;
        QRegularExpression re("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        if(re.match(email).hasMatch())
            e = 1;
        if(password.length()>=8)
            p = 1;
        if(phnum.length()==10)
            ph = 1;
        if(p){
            if(e){
                if(ph){
                    QSqlQuery query, check;
                    int user_exists = 0;
                    check.prepare("select*from login_info where email = :email");
                    check.bindValue(":email", email);
                    check.exec();
                    while(check.next()){
                        user_exists = 1;
                    }
                    if(user_exists){
                        ui->bt_email->setStyleSheet("border: 1px solid red");
                        QMessageBox::information(this, "Error", "An account is already registered under this email.");
                    }
                    else{
                        query.prepare("insert into login_info (name, phnum, email, password) values(:name, :phnum, :email, :password)");
                        query.bindValue(":name", name);
                        query.bindValue(":phnum",phnum);
                        query.bindValue(":email",email);
                        query.bindValue(":password",password);
                        if(query.exec())
                            QMessageBox::information(this, "Registered", "Data inserted sucessfully");
                        ui->bt_email->clear();
                        ui->pass->clear();
                        ui->phnum->clear();
                        ui->name->clear();
                    }
                }
                else{
                    ui->phnum->setStyleSheet("border: 1px solid red");
                    QMessageBox::information(this, "Error", "Please Enter valid Phone number.");
                }
            }
            else{
                ui->bt_email->setStyleSheet("border: 1px solid red");
                QMessageBox::information(this, "Error", "Please Enter valid E-mail.");
            }
        }
        else{
            ui->pass->setStyleSheet("border: 1px solid red");
            QMessageBox::information(this, "Error", "Password must be at least 8 char long.");
        }
    }
    else{

        QMessageBox::information(this, "Error", "Fill in all the input fields to register.");
        ui->name->setStyleSheet("border: 1px solid red");
        ui->phnum->setStyleSheet("border: 1px solid red");
        ui->bt_email->setStyleSheet("border: 1px solid red");
        ui->pass->setStyleSheet("border: 1px solid red");
    }
    db.close();
}



void landing_page2::on_back_clicked()
{
    this->close();
    Bus_Seat_Management_System *mainWindow = new Bus_Seat_Management_System();
    mainWindow->show();
}
