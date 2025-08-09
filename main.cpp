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
#include "image_provider.h"
#include "camerahandler.h"

using namespace std ;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Backend backend ;
    Currunt_time * currunt_time = new Currunt_time ;
    File_opener file_opener ;
    CameraHandler recorder;
    Image_provider * imageProvider = new Image_provider();

    recorder.set_Imgprovider(imageProvider) ;

    file_opener.check_recorded_videos_exist("./recorded_videos") ;

    qmlRegisterSingletonInstance("VideoRecorder", 1, 0, "Camerahandler", &recorder);
    engine.rootContext()->setContextProperty("imageProvider", imageProvider);
    engine.addImageProvider("camera", imageProvider);
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
