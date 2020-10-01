#include "password_change.h"
#include "ui_password_change.h"
 #include "landing_page3.h"
#include<regex>

password_change::password_change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password_change)
{
    ui->setupUi(this);
}

password_change::~password_change()
{
    delete ui;
}





void password_change::on_pushBtn_clicked()
{
   this->close();
    landing_page3 *mainWindow = new landing_page3();
    mainWindow->show();
}

void password_change::on_submit_clicked()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");

    QString email = ui->email->text();
    QString oldp = ui->oldp->text();
    QString newp = ui->newp->text();



    db.open();
    QSqlQuery query, query1;

    if(query.exec("select * from login_info where email='"+email+"' and password='"+oldp+"'")){
        int count=0;

        while(query.next()){
            count++;
        }

        if(count==1){
                query1.prepare("UPDATE login_info SET password= :newp  WHERE email= :email AND password = :oldp");
                query1.bindValue(":newp",newp);
                query1.bindValue(":email",email);
                query1.bindValue(":oldp",oldp);

               if (query1.exec() )
               {
                 QMessageBox::information(this,"Sucessfull","password is changed sucessfully");

               }
                db.close();
                ui->email->clear();
                ui->oldp->clear();
                ui->newp->clear();

            }

        if(count>1 || count<1)
            QMessageBox::information(this,"unsucessfull login","wrong email or password");
                db.close();
                ui->email->clear();
                ui->oldp->clear();
                ui->newp->clear();

   }




}


