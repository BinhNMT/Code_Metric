/*
 * NullLineMetric.cpp
 *
 *  Created on: Apr 11, 2020
 *      Author: BinhNMT
 *      Email: binhmainguyen193@gmail.com
 */
#include "NullLineMetric.h"

bool C_M::NullLineMetric::checkEmptyLine(string codeString)
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
