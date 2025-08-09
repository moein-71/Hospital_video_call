#include "camerahandler.h"

CameraHandler::CameraHandler(QObject *parent)
    : QObject{parent}
{}

CameraHandler::~CameraHandler() {
    stopRecording();
    Thread->quit();
    Thread->wait();
    // delete Thread ;
    // delete recorder ;
}

void CameraHandler::startRecording(const QString& path) {

    // if(recorder->is_showing() == true) return ;

    if(recorder != nullptr) {
        if(recorder->is_showing() == true) return ;
    }

    recorder = new CameraRecorder();
    recorder->set_ImageProvider(this->imgProvider) ;
    Thread = new QThread(this);
    recorder->moveToThread(Thread);

    connect(Thread, &QThread::finished, recorder, &QObject::deleteLater);

    Thread->start();

    QMetaObject::invokeMethod(recorder, "startRecording", Qt::QueuedConnection, Q_ARG(QString, path));
}

void CameraHandler::stopRecording() {

    QMetaObject::invokeMethod(recorder, "stopRecording", Qt::QueuedConnection);

    if(recorder != nullptr) {
        // delete recorder ;
        recorder = nullptr ;
    }
    if(Thread != nullptr) {
        // delete Thread ;
        Thread = nullptr ;
    }
}

void CameraHandler::startArchiving(const QString& path) {
    if(recorder != nullptr) {
        if(recorder->is_showing()) {
            recorder->startArchiving(path) ;
        }
    }
    // else {
    //     startRecording(path) ;
    //     recorder->startArchiving(path) ;
    // }
}

void CameraHandler::set_Imgprovider(Image_provider * imgprovider) {
    this->imgProvider = imgprovider ;
}

