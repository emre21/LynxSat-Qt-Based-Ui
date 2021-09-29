#ifndef CSVWRITER_H
#define CSVWRITER_H



#include <string>
#include <fstream>
#include <iostream>
using namespace std;


#include <QObject>

class CsvWriter
{

public:
    CsvWriter(string t_file_name);
    ~CsvWriter();
    void openFile();
    void writeData(string data);
    void close();
private:
    ofstream* file;
    string file_name;

};

#endif // CSVWRITER_H
