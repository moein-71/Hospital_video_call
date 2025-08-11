#ifndef MAKE_TIME_H
#define MAKE_TIME_H

#include <QObject>
#include <QTimer>
#include <QTime>
#include <QThread>

class Make_time : public QObject
{
    Q_OBJECT

    public:

        explicit Make_time(QObject *parent = nullptr);
        int get_now_second() ;
        int get_now_minute() ;
        int get_now_hour() ;
        void start() ;

    signals:

        void time_updated(const QString & time) ;
        void date_updated(const QString & date) ;

    private slots:

        void updatetime() ;

    private :

        QTimer* timer = nullptr; ;
        QString now_time ;
        QString now_date ;
        int now_second ;
        int now_minute ;
        int now_hour ;

};

#endif // MAKE_TIME_H
