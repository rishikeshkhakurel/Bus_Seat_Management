#ifndef OWNER_PAGE_H
#define OWNER_PAGE_H

#include <QDialog>

namespace Ui {
class owner_page;
}

class owner_page : public QDialog
{
    Q_OBJECT

public:
    explicit owner_page(QWidget *parent = nullptr);
    ~owner_page();

private slots:
    void on_edit_reservation_btn_clicked();

    void on_add_route_btn_clicked();

    void on_remove_route_btn_clicked();

    void on_view_reservation_btn_clicked();

    void on_logout_btn_clicked();

    void validate(QString);

private:
    Ui::owner_page *ui;
};

#endif // OWNER_PAGE_H
