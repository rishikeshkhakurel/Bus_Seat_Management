#ifndef LANDING_PAGE2_H
#define LANDING_PAGE2_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>
#include<QtDebug>
#include<QFileInfo>



namespace Ui {
class landing_page2;

}

class landing_page2 : public QDialog
{

    Q_OBJECT

public:
    explicit landing_page2(QWidget *parent = nullptr);
    ~landing_page2();

private slots:
    void on_register_2_clicked();

    void on_pushButton_clicked();



    void on_back_clicked();

private:
    Ui::landing_page2 *ui;
};

#endif // LANDING_PAGE2_H
