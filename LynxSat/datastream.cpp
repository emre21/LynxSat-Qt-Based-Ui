#include "datastream.h"
#include "ui_datastream.h"

DataStream::DataStream(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataStream)
{
    ui->setupUi(this);
    init_table();
}

DataStream::~DataStream()
{
    delete ui;
}

void DataStream::init_table()
{
    table_widget = new QTableWidget();
    table_widget->setColumnCount(11);
    for(int i = 0; i < 12 ; i++)
    {
        table_widget->setColumnWidth(i,30);
    }

    QStringList horzHeaders;
    horzHeaders <<"ZAMAN" << "SICAKLIK" << "BASINÇ" << "HIZ" << "ENLEM"<< "BOYLAM"<< "YUKSEKLIK"<< "GERİLİM"<< "AÇI-x"<< "AÇI-y"<< "AÇI-z";
    table_widget->setHorizontalHeaderLabels( horzHeaders );

}
