/*
 * NullLineMetric.h
 *
 *  Created on: Apr 11, 2020
 *      Author: BinhNMT
 *      Email: binhmainguyen193@gmail.com
 */
#ifndef NULLLINEMETRIC_H
#define NULLLINEMETRIC_H

#include <string>
using namespace std;

namespace C_M
{
class NullLineMetric
{
public:
    // @brief   : counting number of effect LOCs
    // @param   : a line of input source code
    // @return : true       - empty line
    //           fasle      - not an empty line
    bool checkEmptyLine(string);
};
}

#endif // NULLLINEMETRIC_H
