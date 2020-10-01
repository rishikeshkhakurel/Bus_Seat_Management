QT       += core gui sql
win32:RC_ICONS += logo5.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    landing_page.cpp \
    landing_page2.cpp \
    landing_page3.cpp \
    main.cpp \
    bus_seat_management_system.cpp \
    owner_page.cpp \
    owner_seats.cpp \
    password_change.cpp \
    reservation_details.cpp

HEADERS += \
    bus_seat_management_system.h \
    landing_page.h \
    landing_page2.h \
    landing_page3.h \
    owner_page.h \
    owner_seats.h \
    password_change.h \
    reservation_details.h

FORMS += \
    bus_seat_management_system.ui \
    landing_page.ui \
    landing_page2.ui \
    landing_page3.ui \
    owner_page.ui \
    owner_seats.ui \
    password_change.ui \
    reservation_details.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
RESOURCES+=\
Seat_Icons.qrc
