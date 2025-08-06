#include "backend.h"

Backend::Backend(QObject *parent)
    : QObject{parent}
{}

QString Backend::click() {
    return this->now_click ;
}

void Backend::set_click(const QString& new_click) {
    this -> now_click = new_click ;
    emit this->click_update() ;
}
