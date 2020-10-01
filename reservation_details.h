#ifndef RESERVATION_DETAILS_H
#define RESERVATION_DETAILS_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>
#include<QtDebug>
#include<QFileInfo>

namespace Ui {
class reservation_details;
}

class reservation_details : public QDialog
{
    Q_OBJECT

public:
    explicit reservation_details(QWidget *parent = nullptr);
    ~reservation_details();

private slots:
    void on_reload_btn_clicked();

    void reload();

private:
    Ui::reservation_details *ui;
};

#endif // RESERVATION_DETAILS_H
