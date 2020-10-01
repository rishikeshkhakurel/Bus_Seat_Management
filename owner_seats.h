#ifndef OWNER_SEATS_H
#define OWNER_SEATS_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class owner_seats;
}

class owner_seats : public QDialog
{
    Q_OBJECT

public:
    explicit owner_seats(QWidget *parent = nullptr);
    ~owner_seats();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_unreserve_btn_clicked();

    void on_pushButton_4_clicked();

    void on_swap_btn_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_door_btn_clicked();

    void on_clear_sel_btn_clicked();

    void assign(int);

    void clear_sel();

private:
    Ui::owner_seats *ui;
};

#endif // OWNER_SEATS_H
