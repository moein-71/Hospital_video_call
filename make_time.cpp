#include "make_time.h"
#include <QThread>


Make_time::Make_time(QObject *parent) : QObject{parent}
{}

void Make_time::start() {

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Make_time::updatetime);
    timer->start(1000);
}

int Make_time::get_now_second() {
    return now_second ;
}

int Make_time::get_now_minute() {
    return now_minute ;
}

int Make_time::get_now_hour() {
    return now_hour ;
}

void Make_time::updatetime() {
    now_second = QTime::currentTime().second() ;
    now_minute = QTime::currentTime().minute() ;
    now_hour = QTime::currentTime().hour() ;
    QString newdate = QDate::currentDate().toString("yyyy-MM-dd");
    QString newtime = QTime::currentTime().toString("HH:mm:ss");

    if (newtime != now_time) {
        now_time = newtime;
        emit time_updated(now_time);
    }
    if(newdate != now_date) {
        now_date = newdate ;
        emit date_updated(now_date) ;
    }
}
