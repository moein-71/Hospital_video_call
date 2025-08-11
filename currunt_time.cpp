#include "currunt_time.h"
#include <QCoreApplication>

Currunt_time::Currunt_time(QObject *parent)
    : QObject{parent}
{
    start_second = 0 ; start_minute = 0 ; start_hour = 0 ;
    make_time = new Make_time();
    timethread = new QThread(this);

    make_time->moveToThread(timethread);

    connect(timethread, &QThread::started, make_time, &Make_time::start);

    connect(make_time, &Make_time::time_updated, this, &Currunt_time::time_updated);
    connect(make_time, &Make_time::time_updated, this, &Currunt_time::time_from_start_updated) ;
    connect(make_time, &Make_time::time_updated, this, &Currunt_time::now_second_updated);
    connect(make_time, &Make_time::time_updated, this, &Currunt_time::now_minute_updated);
    connect(make_time, &Make_time::time_updated, this, &Currunt_time::now_hour_updated);

    connect(make_time, &Make_time::date_updated, this, &Currunt_time::date_updated);

    connect(qApp, &QCoreApplication::aboutToQuit, timethread, &QThread::quit);
    connect(timethread, &QThread::finished, make_time, &QObject::deleteLater);

    timethread->start();
}

void Currunt_time::time_updated(const QString& time) {
    now_time = time ;
    emit time_changed() ;
}

void Currunt_time::date_updated(const QString& date) {
    now_date = date ;
    emit date_changed() ;
}

void Currunt_time::now_second_updated() {
    if(m_now_second != make_time->get_now_second()) {
        m_now_second = make_time->get_now_second() ;
        emit now_second_changed() ;
    }
}

void Currunt_time::now_minute_updated() {
    if(m_now_minute != make_time->get_now_minute()) {
        m_now_minute = make_time->get_now_minute() ;
        emit now_minute_changed() ;
    }
}

void Currunt_time::now_hour_updated() {
    if(m_now_hour != make_time->get_now_hour()) {
        m_now_hour = make_time->get_now_hour() ;
        emit now_hour_changed() ;
    }
}

void Currunt_time::set_video_start_time() {
    if(start_second == 0 && start_minute == 0 && start_hour == 0) {
        start_second = make_time->get_now_second() ;
        start_minute = make_time->get_now_minute() ;
        start_hour = make_time->get_now_hour() ;
    }
}

void Currunt_time::end_of_video() {
    start_second = 0 ; start_minute = 0 ; start_hour = 0 ;
}

QString Currunt_time::time() {
    return now_time ;
}

QString Currunt_time::date() {
    return now_date ;
}

int Currunt_time::now_second() {
    return m_now_second ;
}

int Currunt_time::now_minute() {
    return m_now_minute ;
}

int Currunt_time::now_hour() {
    return m_now_hour ;
}

void Currunt_time::time_from_start_updated(const QString & now_time) {

    long long int start_second_sum = start_second + start_minute*60 + start_hour*60*60 ;
    QTime end   = QTime::fromString(now_time, "HH:mm:ss");
    long long int now_second_sum = end.second() + end.minute()*60 + end.hour()*60*60 ;
    long long int second_res = now_second_sum - start_second_sum ;

    int hours   = second_res / 3600;
    int minutes = (second_res % 3600) / 60;
    int seconds = second_res % 60;

    now_time_from_start =
        ((QString::number(hours).size() == 2) ? QString::number(hours) : "0" + QString::number(hours)) + ":" +
        ((QString::number(minutes).size() == 2) ? QString::number(minutes) : "0" + QString::number(minutes)) + ":" +
        ((QString::number(seconds).size() == 2) ? QString::number(seconds) : "0" + QString::number(seconds));

    emit time_from_start_changed() ;
}

QString Currunt_time::time_from_start() {
    if(start_second == 0 && start_minute == 0 && start_hour == 0) {
        return "00:00:00" ;
    }
    return now_time_from_start ;
}


