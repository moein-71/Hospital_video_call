#ifndef CURRUNT_TIME_H
#define CURRUNT_TIME_H
#include "make_time.h"
#include <QThread>
#include <QObject>

class Currunt_time : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString time READ time NOTIFY time_changed FINAL)
    Q_PROPERTY(QString date READ date NOTIFY date_changed FINAL)
    Q_PROPERTY(QString time_from_start READ time_from_start NOTIFY time_from_start_changed FINAL)
    Q_PROPERTY(int now_second READ now_second NOTIFY now_second_changed FINAL)
    Q_PROPERTY(int now_minute READ now_minute NOTIFY now_minute_changed FINAL)
    Q_PROPERTY(int now_hour READ now_hour NOTIFY now_hour_changed FINAL)

    public:

        explicit Currunt_time(QObject *parent = nullptr);
        QString time() ;
        QString date() ;
        int now_second() ;
        int now_minute() ;
        int now_hour() ;
        QString time_from_start() ;

    public slots:

        void time_updated(const QString& time) ;
        void date_updated(const QString& date) ;
        void time_from_start_updated(const QString & now_time) ;
        void now_second_updated() ;
        void now_minute_updated() ;
        void now_hour_updated() ;
        void set_video_start_time() ;
        void end_of_video() ;

    signals:

        void time_changed() ;
        void date_changed() ;
        void time_from_start_changed() ;
        void now_second_changed() ;
        void now_minute_changed() ;
        void now_hour_changed() ;

    private:

        Make_time * make_time = nullptr ;
        QThread * timethread = nullptr ;
        QString now_time ;
        QString now_date ;
        QString now_time_from_start ;
        int start_second ;
        int start_minute ;
        int start_hour ;
        int m_now_second ;
        int m_now_minute ;
        int m_now_hour ;


};

#endif // CURRUNT_TIME_H
