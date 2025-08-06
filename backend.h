#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString click READ click WRITE set_click NOTIFY click_update)

    public:

        explicit Backend(QObject *parent = nullptr);
        QString click() ;

    public slots:

        void set_click(const QString& new_click) ;

    signals:

        void click_update() ;


    private:
        QString now_click ;

};

#endif // BACKEND_H
