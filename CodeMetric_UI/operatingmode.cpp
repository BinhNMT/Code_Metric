#include "operatingmode.h"
#include "ui_mainwindow.h"
#include "CodeMetric.h"
#include "WorkWithTable.h"
#include <fstream>

OperatingMode::OperatingMode(MainWindow *Obj)
{
    PtrObj = Obj;
}

float OperatingMode::singleFileExecution(QString inputFile, unsigned int stdEffort, unsigned int rowNumber)
{
    C_M::CodeMetric codeObject;
    C_M::EffortMetric effordObj;
    float totalEffor;

    // Counting ELoCs
    codeObject.countingElocs(inputFile.toStdString());

    // Counting Effort
    effordObj.estimateEffort(stdEffort, codeObject.getElocs());

    //Creating Table
    WorkWithTable tableObject(PtrObj);
    tableObject.createTable(rowNumber+1);

    /* ------------------ Fills Results ------------------ */
    // File file name
    tableObject.fillTable(inputFile, rowNumber, 0);

    // Fill total LoCs
    tableObject.fillTable(QString::number(codeObject.getLocs()), rowNumber, 1);

    // Fill E-LoCs
    tableObject.fillTable(QString::number(codeObject.getElocs()), rowNumber, 2);

    // Fill Effort
    totalEffor = effordObj.getManday();
    tableObject.fillTable(QString::number(totalEffor), rowNumber, 3);

    return totalEffor;
}

float OperatingMode::multiFileMode(QString listFilesInput, unsigned int stdEffort)
{
    fstream filesList;
    string filePath;
    unsigned int count = 1;
    float totalEffort = 0;

    filesList.open(listFilesInput.toStdString(), ios::in);
    while (!filesList.eof())
    {
        getline(filesList, filePath);
        totalEffort += singleFileExecution(QString::fromStdString(filePath), stdEffort, count);
        count++;
    }

    filesList.close();

    return totalEffort;
}
