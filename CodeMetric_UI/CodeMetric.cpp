/*
 * CodeMetric.cpp
 *
 *  Created on: Apr 11, 2020
 *      Author: BinhNMT
 *      Email: binhmainguyen193@gmail.com
 */

#include <fstream>
#include "CodeMetric.h"

C_M::CodeMetric::CodeMetric(): elocs(0), totalLocs(0)
{
    setFlagToDefault();
}

void C_M::CodeMetric::countingElocs(string sourcePath)
{
    unsigned int cmt = 0, empty = 0;
    string singleLine;
    fstream sourceFile;

    sourceFile.open(sourcePath, ios::in);

    /* Read line by line code in source file */
    while (!sourceFile.eof())
    {
        getline(sourceFile, singleLine);

        if(checkCmtCode(singleLine))
        {
            cmt++;
        }

        else if(checkEmptyLine(singleLine))
        {
            empty++;
        }

        totalLocs++;
    }

    /* counting effect LoCs */
    elocs = totalLocs - cmt - empty;

    sourceFile.close();
}

unsigned int C_M::CodeMetric::getElocs(void)
{
    return elocs;
}

unsigned int C_M::CodeMetric::getLocs(void)
{
    return totalLocs;
}
