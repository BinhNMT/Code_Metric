/*
 * C_Metric_Lib.cpp
 *
 *  Created on: Apr 11, 2020
 *      Author: BinhNMT
 */

#include <iostream>
#include <fstream>
#include "CodeMetric.h"
using namespace C_M;

CodeMetric::CodeMetric(): elocs(0), locs(0), totalLines(0) {}

bool CodeMetric::checkEmptyLine(string codeString)
{
    int length = codeString.length();

    if (length == 0)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

void CodeMetric::countingElocs(string sourcePath)
{
    int pos;
    unsigned int cmt = 0, empty = 0;
    bool isCmt, isEmpty;
    string singleLine;
    fstream sourceFile;
    
    sourceFile.open(sourcePath, ios::in);

    /* Read line by line code in source file */
    while (!sourceFile.eof())
    {
        isCmt = false;
        isEmpty = false;

        getline(sourceFile, singleLine);
        pos = singleLine.find("/");
        
        /* The case that doubt has comments code */
        if(pos > -1)
        {
            isCmt = checkCmtCode(pos, singleLine);
            
            if(isCmt)
            {
                cmt++;
            }
        }

        /* Check whether empty line or not */
        else
        {
            isEmpty = checkEmptyLine(singleLine);

            if(isEmpty)
            {
                empty++;
            }
        }

        totalLines++;
    }

    /* counting effect LoCs */
    elocs = totalLines - cmt - empty;

    sourceFile.close();
}

unsigned int CodeMetric::getElocs(void)
{
    return elocs;
}

unsigned int CodeMetric::getLocs(void)
{
    return locs;
}

unsigned int CodeMetric::getLines(void)
{
    return totalLines;
}
