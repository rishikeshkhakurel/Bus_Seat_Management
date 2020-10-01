#ifndef BUS_SEAT_MANAGEMENT_SYSTEM_H
#define BUS_SEAT_MANAGEMENT_SYSTEM_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>
#include<QtDebug>
#include<QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class Bus_Seat_Management_System; }
QT_END_NAMESPACE

class Bus_Seat_Management_System : public QMainWindow
{
    Q_OBJECT

public:
    Bus_Seat_Management_System(QWidget *parent = nullptr);
    ~Bus_Seat_Management_System();

private slots:
    void on_log_in_clicked();

    void on_sign_up_clicked();

private:
    Ui::Bus_Seat_Management_System *ui;

};
#endif // BUS_SEAT_MANAGEMENT_SYSTEM_H
