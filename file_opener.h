#ifndef FILE_OPENER_H
#define FILE_OPENER_H

#include <QObject>

class File_opener : public QObject
{
    Q_OBJECT
public:
    explicit File_opener(QObject *parent = nullptr);

    Q_INVOKABLE void open_folder(const QString &folder_path);
    void check_recorded_videos_exist(const QString &folder_path) ;

signals:
};

#endif // FILE_OPENER_H
