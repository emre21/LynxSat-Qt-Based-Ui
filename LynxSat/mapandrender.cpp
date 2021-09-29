#include "mapandrender.h"
#include "ui_mapandrender.h"

MapAndRender::MapAndRender(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapAndRender)
{
    ui->setupUi(this);

    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/View.qml")));
    ui->quickWidget->rootObject()->setProperty("width",this->width());
}

void MapAndRender::update_ui(qreal euler_1,qreal euler_2,qreal euler_3,qreal map_x,qreal map_y)
{
    QObject *object = ui->quickWidget->rootObject();
    object->setProperty("render_euler_1", euler_1);
    object->setProperty("render_euler_2", euler_2);
    object->setProperty("render_euler_3", euler_3);
    object->setProperty("map_X", map_x);
    object->setProperty("map_Y", map_y);

}
MapAndRender::~MapAndRender()
{
    delete ui;
}
