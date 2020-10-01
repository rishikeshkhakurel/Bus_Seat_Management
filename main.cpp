#include "bus_seat_management_system.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bus_Seat_Management_System w;
    w.show();
    return a.exec();
}
