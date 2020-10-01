#ifndef PASSWORD_CHANGE_H
#define PASSWORD_CHANGE_H

#include <QDialog>

namespace Ui {
class password_change;
}

class password_change : public QDialog
{
    Q_OBJECT

public:
    explicit password_change(QWidget *parent = nullptr);
    ~password_change();

private slots:


    void on_pushBtn_clicked();

    void on_submit_clicked();

private:
    Ui::password_change *ui;
};

#endif // PASSWORD_CHANGE_H
