#ifndef IMAGE_PROVIDER_H
#define IMAGE_PROVIDER_H

#include <QQuickImageProvider>
#include <QImage>
#include <QMutex>

class Image_provider : public QQuickImageProvider
{
    Q_OBJECT
    public:
        Image_provider();

        QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;

    public slots:
        void setImage(const QImage &img) ;

    signals:
        void imageChanged();

    private:
        QImage image;
        QMutex mutex;
};

#endif // IMAGE_PROVIDER_H
