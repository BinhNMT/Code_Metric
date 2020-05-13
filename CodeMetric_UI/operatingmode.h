#ifndef OPERATINGMODE_H
#define OPERATINGMODE_H

#include "mainwindow.h"

class OperatingMode
{
private:
    MainWindow *PtrObj;
public:
    OperatingMode(MainWindow*);
    float singleFileExecution(QString, unsigned int, unsigned int rowNumber = 1);
    float multiFileMode(QString, unsigned int);
};

#endif // OPERATINGMODE_H
