#ifndef WORKWITHTABLE_H
#define WORKWITHTABLE_H

#include "mainwindow.h"

class WorkWithTable
{
private:
    MainWindow *PtrObj;
public:
    WorkWithTable(MainWindow*);
    void createTable(unsigned int rowNumber = 2);
    void fillTable(QString, int, int);
};
#endif // WORKWITHTABLE_H
