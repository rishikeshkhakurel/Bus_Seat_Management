#ifndef LANDING_PAGE3_H
#define LANDING_PAGE3_H

#include <QDialog>
#include<QSqlDatabase>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<landing_page.h>



namespace Ui {
class landing_page3;
}

class landing_page3 : public QDialog
{
    Q_OBJECT

public:
    explicit landing_page3(QWidget *parent = nullptr);
    ~landing_page3();



private slots:


    void on_see_seat_clicked();

    void on_pushButton_4_clicked();

    void on_back_clicked();

    void on_From_activated(const QString &arg1);

    void on_change_ps_btn_clicked();

private:
    Ui::landing_page3 *ui;
};





#endif // LANDING_PAGE3_H
