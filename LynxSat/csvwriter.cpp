#include "csvwriter.h"


CsvWriter::CsvWriter(string t_file_name)
{
    this->file_name = t_file_name;
}

CsvWriter::~CsvWriter()
{
    delete file;
}
void CsvWriter::openFile()
{
    file = new ofstream();
    file->open(file_name);

    if (!file->is_open())
    {
        cout << "DOSYA ACILMADI";
    }
}

void CsvWriter::writeData(string t_data)
{
    //t_data = t_data + '\n';
    file->write(t_data.c_str(), t_data.size());

}

void CsvWriter::close()
{
    file->close();
}
