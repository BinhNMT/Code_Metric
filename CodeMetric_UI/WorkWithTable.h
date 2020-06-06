/*
 * WorkWithTable.h
 *
 *  Created on: Apr 11, 2020
 *      Author: BinhNMT
 *      Email: binhmainguyen193@gmail.com
 */
#ifndef WORKWITHTABLE_H
#define WORKWITHTABLE_H

#include "mainwindow.h"

class WorkWithTable
{
private:
    MainWindow *PtrObj;

    // @brief   : Creating an output result table form.
    // @param   : rowNumber     - the number of rows that will be created in the table. Deafault is 2.
    void createTable(unsigned int rowNumber = 2);

public:
    WorkWithTable(MainWindow*, unsigned int);

    // @brief   : Filling to the particular cell of the table.
    // @param   : inputString   - the content that needs to be filled into the table.
    //            row           - the row coordinate of the cell.
    //            col           - the column coordinate of the cell.
    void fillTable(QString, int, int);
};

#endif // WORKWITHTABLE_H
