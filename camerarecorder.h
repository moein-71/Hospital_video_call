#ifndef CAMERARECORDER_H
#define CAMERARECORDER_H

#include <QObject>
#include <QImage>
#include <QTimer>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QThread>
#include <opencv2/opencv.hpp>
#include "image_provider.h"

class CameraRecorder : public QObject
{
    Q_OBJECT
    public:
        explicit CameraRecorder(QObject *parent = nullptr) ;

        Q_INVOKABLE void startRecording(const QString& path) ;
        Q_INVOKABLE void stopRecording() ;

        void set_ImageProvider(Image_provider* provider) ;
        bool is_showing() ;
        void startArchiving(const QString &path) ;

    signals:
        // void frameReady(const QImage &image);
        void frameImageChanged();

    private slots:
        void captureFrame();

    private:
        QTimer * frameTimer = nullptr ;
        QImage m_frameImage;
        cv::VideoCapture cap;
        cv::VideoWriter writer;
        bool isRecording = false ;
        bool isShowing = false ;
        Image_provider * imgProvider = nullptr;
};

#endif // CAMERARECORDER_H
