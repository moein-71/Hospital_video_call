#include "currunt_time.h"
#include <QCoreApplication>

Currunt_time::Currunt_time(QObject *parent)
    : QObject{parent}
{
    make_time = new Make_time();
    timethread = new QThread(this);

    make_time->moveToThread(timethread);

    connect(timethread, &QThread::started, make_time, &Make_time::start);
    connect(make_time, &Make_time::time_updated, this, &Currunt_time::time_updated);
    connect(make_time, &Make_time::date_updated, this, &Currunt_time::date_updated);

    connect(qApp, &QCoreApplication::aboutToQuit, timethread, &QThread::quit);
    connect(timethread, &QThread::finished, make_time, &QObject::deleteLater);

    timethread->start();
}

void Currunt_time::time_updated(const QString& time) {
    now_time = time ;
    emit this->time_changed() ;
}

void Currunt_time::date_updated(const QString& date) {
    now_date = date ;
    emit this->date_changed() ;
}

QString Currunt_time::time() {
    return now_time ;
}

QString Currunt_time::date() {
    return now_date ;
}
