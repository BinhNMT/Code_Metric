/*
 * OperatingMode.h
 *
 *  Created on: Apr 11, 2020
 *      Author: BinhNMT
 *      Email: binhmainguyen193@gmail.com
 */
#ifndef OPERATINGMODE_H
#define OPERATINGMODE_H

#include "mainwindow.h"

namespace C_M
{
class OperatingMode
{
private:
    MainWindow *PtrObj;
public:
    OperatingMode(MainWindow*);

    // @brief   : Execute the complete task of the metric program for a single file.
    // @param   : inputFile     - path of the file that needs to metric.
    //            stdEffort     - the standard effort for a day which counted by eLocs.
    //            rowNumber     - the position of the row that will be filled. Default is 1.
    // @return  : The effort which was counted.
    float singleFileExecution(QString, unsigned int, unsigned int rowNumber = 1);

    // @brief   : Execute the complete task of the metric program for multiple file.
    // @param   : inputFile     - path of the file that needs to metric.
    //            stdEffort     - the standard effort for a day which counted by eLocs.
    // @return  : The total effort which was counted.
    float multiFileMode(QString, unsigned int);
};
}

#endif // OPERATINGMODE_H
