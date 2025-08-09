#ifndef CAMERAHANDLER_H
#define CAMERAHANDLER_H

#include <QObject>
#include <QObject>
#include <QImage>
#include <QTimer>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QThread>
#include "image_provider.h"
#include "camerarecorder.h"

class CameraHandler : public QObject
{
    Q_OBJECT
    public:
        explicit CameraHandler(QObject *parent = nullptr);
        ~CameraHandler();

        Q_INVOKABLE void startRecording(const QString& path); // this is for showing the frames
        Q_INVOKABLE void stopRecording();

        Q_INVOKABLE void startArchiving(const QString& path);

        void set_Imgprovider(Image_provider * imgprovider) ;

    private:
        CameraRecorder * recorder = nullptr;
        QThread* Thread = nullptr;
        Image_provider * imgProvider = nullptr;

};

#endif // CAMERAHANDLER_H
