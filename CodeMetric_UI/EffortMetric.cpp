/*
 * EffortMetric.cpp
 *
 *  Created on: Apr 16, 2020
 *      Author: BinhNMT
 *      Email: binhmainguyen193@gmail.com
 */

#include <iostream>
#include "EffortMetric.h"

C_M::EffortMetric::EffortMetric(): manday(0) {}

void C_M::EffortMetric::estimateEffort(unsigned int effortPerDay = 0, unsigned int eLocs = 0)
{
    manday = ((float)eLocs / (float)effortPerDay);
}

float C_M::EffortMetric::getManday()
{
    return manday;
}
