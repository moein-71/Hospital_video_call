#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#include <QCoreApplication>
#include <QQmlEngine>
#include <QQmlExtensionPlugin>
#include <QFile>

#include "backend.h"
#include "currunt_time.h"
#include "file_opener.h"

using namespace std ;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Backend backend ;
    Currunt_time * currunt_time = new Currunt_time ;
    File_opener file_opener ;

    file_opener.check_recorded_videos_exist("./recorded_videos") ;

    engine.rootContext()->setContextProperty("currunt_time", currunt_time);
    engine.rootContext()->setContextProperty("backend", &backend);
    engine.rootContext()->setContextProperty("file_opener" , &file_opener) ;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Hospital_project", "Main");

    //delete currunt_time

    return app.exec();
}
