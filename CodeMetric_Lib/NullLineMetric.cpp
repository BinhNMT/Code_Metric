/*
 * NullLineMetric.cpp
 *
 *  Created on: Apr 11, 2020
 *      Author: BinhNMT
 *      Email: binhmainguyen193@gmail.com
 */

#include <iostream>
#include "CodeMetric.h"
using namespace C_M;

bool NullLineMetric::checkEmptyLine(string codeString)
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