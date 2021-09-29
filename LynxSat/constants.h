/*
 * FOR FILENAMES AND DIRECTORIES
 *
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H



#include <QString>

class Constants
{

public:
    Constants* getInstance() const;
    static QString s_Working_Dir;
    static QString s_Video_Name;
    static QString s_telemetry_file;

private:
    Constants();


};

#endif // CONSTANTS_H
