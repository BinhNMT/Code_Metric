/*
 * WorkWithTable.cpp
 *
 *  Created on: Apr 11, 2020
 *      Author: BinhNMT
 *      Email: binhmainguyen193@gmail.com
 */
#include "mainwindow.h"
#include "WorkWithTable.h"
#include "ui_mainwindow.h"

WorkWithTable::WorkWithTable(MainWindow *Obj, unsigned int rowNumber)
{
    PtrObj = Obj;
    createTable(rowNumber);
}


void WorkWithTable::createTable(unsigned int rowNumber)
{
    /* ------------------ Creating Table ------------------ */
    PtrObj->ui->tableWidget->setRowCount(rowNumber);
    PtrObj->ui->tableWidget->setColumnCount(4);
    QString arr_Header[4] = {"File name", "Total LoCs", "ELoC", "Effort(Manday)"};

    for (int col = 0; col < 4; col++)
    {
        QTableWidgetItem *tabObj = new QTableWidgetItem();
        tabObj->setText(arr_Header[col]);
        tabObj->setTextAlignment(Qt::AlignCenter);
        PtrObj->ui->tableWidget->setItem(0, col, tabObj);
    }
}


void WorkWithTable::fillTable(QString inputString, int row, int col)
{
    QTableWidgetItem *tabObj = new QTableWidgetItem();
    tabObj->setText(inputString);
    tabObj->setTextAlignment(Qt::AlignLeft);
    PtrObj->ui->tableWidget->setItem(row, col, tabObj);
}
