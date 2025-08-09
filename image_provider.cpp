#include "image_provider.h"


Image_provider::Image_provider() : QQuickImageProvider(QQuickImageProvider::Image) {
}

QImage Image_provider::requestImage(const QString &id, QSize *size, const QSize &requestedSize) {
    QMutexLocker locker(&mutex);

    if (image.isNull())
        return QImage();

    if (size)
        *size = image.size();

    if (requestedSize.width() > 0 && requestedSize.height() > 0)
        return image.scaled(requestedSize);

    return image;
}

void Image_provider::setImage(const QImage &img) {
    QMutexLocker locker(&mutex);
    image = img.copy();
    emit imageChanged();
}

