#include "file_opener.h"
#include <QDesktopServices>
#include <QUrl>
#include <QDir>

File_opener::File_opener(QObject *parent)
    : QObject{parent}
{}

void File_opener::open_folder(const QString &folder_path) {

    QUrl folder_url = QUrl::fromLocalFile(QDir(folder_path).absolutePath());
    QDesktopServices::openUrl(folder_url);
}

void File_opener::check_recorded_videos_exist(const QString &folder_path) {

    QDir dir(folder_path);

    if(!dir.exists()) {
        qDebug() << "Directory does not exist. Creating:" << folder_path;

        if (dir.mkpath(".")) {}
        else {
            qDebug() << "Failed to create directory!";
        }
    }
}

