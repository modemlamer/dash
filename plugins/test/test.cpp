#include <QDebug>
#include <QTimer>

#include "test.hpp"

Test::Test()
{
    this->climate = new Climate();
    this->climate->set_max_fan_speed(4);
    this->climate->setProperty("tab_title", "Climate");

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this]() {
        this->climate->set_fan_speed(rand() % 5);
        switch(rand() % 6) {
            case 0:
                climate->set_airflow(0b101);
                break;
            case 1:
                climate->set_airflow(0b010);
                break;
            case 2:
                climate->set_airflow(0b110);
                break;
            case 3:
                climate->set_airflow(0b100);
                break;
            case 4:
                climate->set_airflow(0b001);
                break;
            default:
                climate->set_airflow(0b000);
                break;
        }
    });
    timer->start(100);

    QTimer *timer2 = new QTimer(this);
    connect(timer2, &QTimer::timeout, [this]() {
        this->climate->set_driver_temp((rand() % 20) + 60);
        this->climate->set_passenger_temp((rand() % 20) + 60);
    });
    timer2->start(150);
}

QList<QWidget *> Test::tabs()
{
    QList<QWidget *> tabs;
    tabs.append(this->climate);
    return tabs;
}