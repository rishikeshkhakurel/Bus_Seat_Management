#include "landing_page.h"

#include "ui_landing_page.h"


landing_page::landing_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::landing_page)
{
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    ui->setupUi(this);


    QString fromto;
    int resseat;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");
    db.open();

        QSqlQuery query,query1,query2,query3,query4,query5,query6,query7,query8,query9,query10,query11,query12,query13,query14,query15;
        QSqlQuery query16,query17,query18,query19,query20;
         QSqlQuery query21,query22,query23,query24,query25,query26,query27,query28,query29,query30,query31,query32;

        query.exec("select * from tempp");
        int c = query.record().indexOf("name");
        while(query.next()){
        fromto=query.value(c).toString();
        }
        query2.exec("drop table tempp");
        query1.exec("select is_Reserved from "+fromto+" where Seat_Number=1");


        int b = query1.record().indexOf("is_Reserved");
        while (query1.next()) {

                resseat = query1.value(b).toInt();

            }


        if(resseat==1){

            ui->pushButton->setStyleSheet("border-image: url(:/Bus_Icons/Icon_1_red.png);");

            }

        if(resseat==0){

            ui->pushButton->setStyleSheet("border-image: url(:/Bus_Icons/Icon_1_black.png);");

        }

        query3.exec("select is_Reserved from "+fromto+" where Seat_Number=2");
        b=query3.record().indexOf("is_Reserved");

        while (query3.next()) {

                resseat = query3.value(b).toInt();

            }


        if(resseat==1){

            ui->pushButton_2->setStyleSheet("border-image: url(:/Bus_Icons/Icon_2_red.png);");

            }

        if(resseat==0){

            ui->pushButton_2->setStyleSheet("border-image: url(:/Bus_Icons/Icon_2_black.png);");

        }

        query4.exec("select is_Reserved from "+fromto+" where Seat_Number=3");
        b = query4.record().indexOf("is_Reserved");
        while (query4.next()) {

                resseat = query4.value(b).toInt();

            }


        if(resseat==1){

            ui->pushButton_3->setStyleSheet("border-image: url(:/Bus_Icons/Icon_3_red.png);");

            }

        if(resseat==0){

            ui->pushButton_3->setStyleSheet("border-image: url(:/Bus_Icons/Icon_3_black.png);");

        }
        query5.exec("select is_Reserved from "+fromto+" where Seat_Number=4");
        b = query5.record().indexOf("is_Reserved");

        while (query5.next()) {

                resseat = query5.value(b).toInt();

            }


        if(resseat==1){

            ui->pushButton_4->setStyleSheet("border-image: url(:/Bus_Icons/Icon_4_red.png);");

            }

        if(resseat==0){

            ui->pushButton_4->setStyleSheet("border-image: url(:/Bus_Icons/Icon_4_black.png);");

        }

        query6.exec("select is_Reserved from "+fromto+" where Seat_Number=5");
        b = query6.record().indexOf("is_Reserved");

        while (query6.next()) {
                resseat = query6.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_5->setStyleSheet("border-image: url(:/Bus_Icons/Icon_5_red.png);");

            }

        if(resseat==0){

            ui->pushButton_5->setStyleSheet("border-image: url(:/Bus_Icons/Icon_5_black.png);");

        }

        query7.exec("select is_Reserved from "+fromto+" where Seat_Number=6");
        b = query7.record().indexOf("is_Reserved");

        while (query7.next()) {
                resseat = query7.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_6->setStyleSheet("border-image: url(:/Bus_Icons/Icon_6_red.png);");

            }

        if(resseat==0){

            ui->pushButton_6->setStyleSheet("border-image: url(:/Bus_Icons/Icon_6_black.png);");

        }

        query8.exec("select is_Reserved from "+fromto+" where Seat_Number=7");
        b = query8.record().indexOf("is_Reserved");

        while (query8.next()) {
                resseat = query8.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_7->setStyleSheet("border-image: url(:/Bus_Icons/Icon_7_red.png);");

            }

        if(resseat==0){

            ui->pushButton_7->setStyleSheet("border-image: url(:/Bus_Icons/Icon_7_black.png);");

        }

        query9.exec("select is_Reserved from "+fromto+" where Seat_Number=8");
        b = query9.record().indexOf("is_Reserved");

        while (query9.next()) {
                resseat = query9.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_8->setStyleSheet("border-image: url(:/Bus_Icons/Icon_8_red.png);");

            }

        if(resseat==0){

            ui->pushButton_8->setStyleSheet("border-image: url(:/Bus_Icons/Icon_8_black.png);");

        }

        query10.exec("select is_Reserved from "+fromto+" where Seat_Number=9");
        b = query10.record().indexOf("is_Reserved");

        while (query10.next()) {
                resseat = query10.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_9->setStyleSheet("border-image: url(:/Bus_Icons/Icon_9_red.png);");

            }

        if(resseat==0){

            ui->pushButton_9->setStyleSheet("border-image: url(:/Bus_Icons/Icon_9_black.png);");

        }

        query11.exec("select is_Reserved from "+fromto+" where Seat_Number=10");
        b = query11.record().indexOf("is_Reserved");


        while (query11.next()) {
                resseat = query11.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_10->setStyleSheet("border-image: url(:/Bus_Icons/Icon_10_red.png);");

            }

        if(resseat==0){

            ui->pushButton_10->setStyleSheet("border-image: url(:/Bus_Icons/Icon_10_black.png);");

        }

        query12.exec("select is_Reserved from "+fromto+" where Seat_Number=11");
        b = query12.record().indexOf("is_Reserved");



        while (query12.next()) {
                resseat = query12.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_11->setStyleSheet("border-image: url(:/Bus_Icons/Icon_11_red.png);");

            }

        if(resseat==0){

            ui->pushButton_11->setStyleSheet("border-image: url(:/Bus_Icons/Icon_11_black.png);");

        }

        query13.exec("select is_Reserved from "+fromto+" where Seat_Number=12");
        b = query13.record().indexOf("is_Reserved");


        while (query13.next()) {
                resseat = query13.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_12->setStyleSheet("border-image: url(:/Bus_Icons/Icon_12_red.png);");

            }

        if(resseat==0){

            ui->pushButton_12->setStyleSheet("border-image: url(:/Bus_Icons/Icon_12_black.png);");

        }

        query14.exec("select is_Reserved from "+fromto+" where Seat_Number=13");
        b = query14.record().indexOf("is_Reserved");


        while (query14.next()) {
                resseat = query14.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_13->setStyleSheet("border-image: url(:/Bus_Icons/Icon_13_red.png);");

            }

        if(resseat==0){

            ui->pushButton_13->setStyleSheet("border-image: url(:/Bus_Icons/Icon_13_black.png);");

        }

        query15.exec("select is_Reserved from "+fromto+" where Seat_Number=14");
        b = query15.record().indexOf("is_Reserved");


        while (query15.next()) {
                resseat = query15.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_14->setStyleSheet("border-image: url(:/Bus_Icons/Icon_14_red.png);");

            }

        if(resseat==0){

            ui->pushButton_14->setStyleSheet("border-image: url(:/Bus_Icons/Icon_14_black.png);");

        }

        query16.exec("select is_Reserved from "+fromto+" where Seat_Number=15");
        b = query16.record().indexOf("is_Reserved");

        while (query16.next()) {
                resseat = query16.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_15->setStyleSheet("border-image: url(:/Bus_Icons/Icon_15_red.png);");

            }

        if(resseat==0){

            ui->pushButton_15->setStyleSheet("border-image: url(:/Bus_Icons/Icon_15_black.png);");

        }

        query17.exec("select is_Reserved from "+fromto+" where Seat_Number=16");
        b = query17.record().indexOf("is_Reserved");


        while (query17.next()) {
                resseat = query17.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_16->setStyleSheet("border-image: url(:/Bus_Icons/Icon_16_red.png);");

            }

        if(resseat==0){

            ui->pushButton_16->setStyleSheet("border-image: url(:/Bus_Icons/Icon_16_black.png);");

        }

        query18.exec("select is_Reserved from "+fromto+" where Seat_Number=17");
        b = query18.record().indexOf("is_Reserved");


        while (query18.next()) {
                resseat = query18.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_17->setStyleSheet("border-image: url(:/Bus_Icons/Icon_17_red.png);");

            }

        if(resseat==0){

            ui->pushButton_17->setStyleSheet("border-image: url(:/Bus_Icons/Icon_17_black.png);");

        }

        query19.exec("select is_Reserved from "+fromto+" where Seat_Number=18");
        b = query19.record().indexOf("is_Reserved");



        while (query19.next()) {
                resseat = query19.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_18->setStyleSheet("border-image: url(:/Bus_Icons/Icon_18_red.png);");

            }

        if(resseat==0){

            ui->pushButton_18->setStyleSheet("border-image: url(:/Bus_Icons/Icon_18_black.png);");

        }

        query20.exec("select is_Reserved from "+fromto+" where Seat_Number=19");
        b = query20.record().indexOf("is_Reserved");



        while (query20.next()) {
                resseat = query20.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_19->setStyleSheet("border-image: url(:/Bus_Icons/Icon_19_red.png);");

            }

        if(resseat==0){

            ui->pushButton_19->setStyleSheet("border-image: url(:/Bus_Icons/Icon_19_black.png);");

        }

        query21.exec("select is_Reserved from "+fromto+" where Seat_Number=20");
        b = query21.record().indexOf("is_Reserved");

        while (query21.next()) {
                resseat = query21.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_20->setStyleSheet("border-image: url(:/Bus_Icons/Icon_20_red.png);");

            }

        if(resseat==0){

            ui->pushButton_20->setStyleSheet("border-image: url(:/Bus_Icons/Icon_20_black.png);");

        }

        query22.exec("select is_Reserved from "+fromto+" where Seat_Number=21");
        b = query22.record().indexOf("is_Reserved");

        while (query22.next()) {
                resseat = query22.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_21->setStyleSheet("border-image: url(:/Bus_Icons/Icon_21_red.png);");

            }

        if(resseat==0){

            ui->pushButton_21->setStyleSheet("border-image: url(:/Bus_Icons/Icon_21_black.png);");

        }

        query23.exec("select is_Reserved from "+fromto+" where Seat_Number=22");
        b = query23.record().indexOf("is_Reserved");

        while (query23.next()) {
                resseat = query23.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_22->setStyleSheet("border-image: url(:/Bus_Icons/Icon_22_red.png);");

            }

        if(resseat==0){

            ui->pushButton_22->setStyleSheet("border-image: url(:/Bus_Icons/Icon_22_black.png);");

        }

        query24.exec("select is_Reserved from "+fromto+" where Seat_Number=23");
        b = query24.record().indexOf("is_Reserved");


        while (query24.next()) {
                resseat = query24.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_23->setStyleSheet("border-image: url(:/Bus_Icons/Icon_23_red.png);");

            }

        if(resseat==0){

            ui->pushButton_23->setStyleSheet("border-image: url(:/Bus_Icons/Icon_23_black.png);");

        }

        query25.exec("select is_Reserved from "+fromto+" where Seat_Number=24");
        b = query25.record().indexOf("is_Reserved");


        while (query25.next()) {
                resseat = query25.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_24->setStyleSheet("border-image: url(:/Bus_Icons/Icon_24_red.png);");

            }

        if(resseat==0){

            ui->pushButton_24->setStyleSheet("border-image: url(:/Bus_Icons/Icon_24_black.png);");

        }

        query26.exec("select is_Reserved from "+fromto+" where Seat_Number=25");
        b = query26.record().indexOf("is_Reserved");

        while (query26.next()) {
                resseat = query26.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_25->setStyleSheet("border-image: url(:/Bus_Icons/Icon_25_red.png);");

            }

        if(resseat==0){

            ui->pushButton_25->setStyleSheet("border-image: url(:/Bus_Icons/Icon_25_black.png);");

        }

        query27.exec("select is_Reserved from "+fromto+" where Seat_Number=26");
        b = query27.record().indexOf("is_Reserved");

        while (query27.next()) {
                resseat = query27.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_26->setStyleSheet("border-image: url(:/Bus_Icons/Icon_26_red.png);");

            }

        if(resseat==0){

            ui->pushButton_26->setStyleSheet("border-image: url(:/Bus_Icons/Icon_26_black.png);");

        }

        query28.exec("select is_Reserved from "+fromto+" where Seat_Number=27");
        b = query28.record().indexOf("is_Reserved");

        while (query28.next()) {
                resseat = query28.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_27->setStyleSheet("border-image: url(:/Bus_Icons/Icon_27_red.png);");

            }

        if(resseat==0){

            ui->pushButton_27->setStyleSheet("border-image: url(:/Bus_Icons/Icon_27_black.png);");

        }

        query29.exec("select is_Reserved from "+fromto+" where Seat_Number=28");
        b = query29.record().indexOf("is_Reserved");


        while (query29.next()) {
                resseat = query29.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_28->setStyleSheet("border-image: url(:/Bus_Icons/Icon_28_red.png);");

            }

        if(resseat==0){

            ui->pushButton_28->setStyleSheet("border-image: url(:/Bus_Icons/Icon_28_black.png);");

        }

        query30.exec("select is_Reserved from "+fromto+" where Seat_Number=29");
        b = query30.record().indexOf("is_Reserved");


        while (query30.next()) {
                resseat = query30.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_29->setStyleSheet("border-image: url(:/Bus_Icons/Icon_29_red.png);");

            }

        if(resseat==0){

            ui->pushButton_29->setStyleSheet("border-image: url(:/Bus_Icons/Icon_29_black.png);");

        }

        query31.exec("select is_Reserved from "+fromto+" where Seat_Number=30");
        b = query31.record().indexOf("is_Reserved");

        while (query31.next()) {
                resseat = query31.value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_30->setStyleSheet("border-image: url(:/Bus_Icons/Icon_30_red.png);");

            }

        if(resseat==0){

            ui->pushButton_30->setStyleSheet("border-image: url(:/Bus_Icons/Icon_30_black.png);");

        }

        query32.exec("select is_Reserved from "+fromto+" where Seat_Number=31");
        b = query32.record().indexOf("is_Reserved");

        while (query32.next()) {
                resseat = query32 .value(b).toInt();
            }

        if(resseat==1){

            ui->pushButton_31->setStyleSheet("border-image: url(:/Bus_Icons/Icon_31_red.png);");

            }

        if(resseat==0){

            ui->pushButton_31->setStyleSheet("border-image: url(:/Bus_Icons/Icon_31_black.png);");

        }
db.close();

}

landing_page::~landing_page()
{
    delete ui;
}



/*
void landing_page::on_pushButton_36_clicked()
{

    QString from_to="kathmandupokhara";
    for(int i = 5; i<=31; i++){
            QSqlDatabase db;
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("E:/project/Bus_Seat_Management_System/bus.db");
            db.open();
            QSqlQuery fill;
            fill.prepare("insert into "+from_to+"(Seat_Number, is_Reserved) values(:val, 0)");
            fill.bindValue(":val", i);
            fill.exec();
            db.close();

        }

}
*/
