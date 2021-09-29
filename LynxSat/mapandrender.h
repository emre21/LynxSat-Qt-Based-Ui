#ifndef MAPANDRENDER_H
#define MAPANDRENDER_H

#include <QWidget>

#include <QQmlProperty>
#include <QQuickItem>
#include <QQmlEngine>
#include <QtQml>
#include <QQmlComponent>

namespace Ui {
class MapAndRender;
}

class MapAndRender : public QWidget
{
    Q_OBJECT

public:
    explicit MapAndRender(QWidget *parent = nullptr);
    ~MapAndRender();

    void update_ui(qreal euler_1,qreal euler_2,qreal euler_3,qreal map_x,qreal map_y);

private:
    Ui::MapAndRender *ui;
};

#endif // MAPANDRENDER_H
