#ifndef DATASTREAM_H
#define DATASTREAM_H

#include <QWidget>
#include <QTableWidget>
namespace Ui {
class DataStream;
}

class DataStream : public QWidget
{
    Q_OBJECT

public:
    explicit DataStream(QWidget *parent = nullptr);
    ~DataStream();

private:
    Ui::DataStream *ui;
    QTableWidget* table_widget;
    void init_table();
};

#endif // DATASTREAM_H
