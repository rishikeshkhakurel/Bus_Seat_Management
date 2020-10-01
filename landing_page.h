#ifndef LANDING_PAGE_H
#define LANDING_PAGE_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>
#include<QtDebug>
#include<QFileInfo>
#include<QPushButton>


namespace Ui {
class landing_page;
}

class landing_page : public QDialog
{
    Q_OBJECT

public:
    explicit landing_page(QWidget *parent = nullptr);
    ~landing_page();

private slots:
    void on_pushButton_36_clicked();

private:
    Ui::landing_page *ui;
};



#endif // LANDING_PAGE_H
