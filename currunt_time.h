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

    public:

        explicit Currunt_time(QObject *parent = nullptr);
        QString time() ;
        QString date() ;

    public slots:

        void time_updated(const QString& time) ;
        void date_updated(const QString& date) ;

    signals:

        void time_changed() ;
        void date_changed() ;

    private:

        Make_time * make_time = nullptr ;
        QThread * timethread = nullptr ;
        QString now_time ;
        QString now_date ;


};

#endif // CURRUNT_TIME_H
