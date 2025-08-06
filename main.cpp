#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#include <QCoreApplication>
#include <QQmlEngine>
#include <QQmlExtensionPlugin>

#include "backend.h"
#include "currunt_time.h"

using namespace std ;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Backend backend ;
    Currunt_time * currunt_time = new Currunt_time ;

    engine.rootContext()->setContextProperty("currunt_time", currunt_time);
    engine.rootContext()->setContextProperty("backend", &backend);

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
