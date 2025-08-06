#include "make_time.h"
#include <QThread>


Make_time::Make_time(QObject *parent) : QObject{parent}
{}

void Make_time::start() {

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Make_time::updatetime);
    timer->start(1000);
}


void Make_time::updatetime() {
    QString newtime = QTime::currentTime().toString("HH:mm:ss");
    QString newdate = QDate::currentDate().toString("yyyy-MM-dd");

    if (newtime != now_time) {
        now_time = newtime;
        emit time_updated(now_time);
    }
    if(newdate != now_date) {
        now_date = newdate ;
        emit date_updated(now_date) ;
    }
}
