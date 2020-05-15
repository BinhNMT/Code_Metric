/*
 * CodeMetric.h
 *
 *  Created on: Apr 11, 2020
 *      Author: BinhNMT
 *      Email: binhmainguyen193@gmail.com
 */
#ifndef CODEMETRIC_H
#define CODEMETRIC_H

#include <string>
#include "CommentMetric.h"
#include "NullLineMetric.h"
using namespace std;

#define NOTCMT      0
#define ISCMT       1
#define BLOCK       2

namespace C_M
{
class CodeMetric: public CommentMetric, NullLineMetric
{
private:
    /* properties */
    unsigned int elocs;
    unsigned int totalLocs;
    unsigned int totalLines;

public:
    /* class constructor */
    CodeMetric();

    // @brief   : counting number of effect LOCs
    // @param   : path/to/source/file
    void countingElocs(string);

    // @brief   : get effected Line of Code values
    // @return  : number of effect loCs
    unsigned int getElocs(void);

    // @brief   : get total exist Line of Code values
    // @return  : number of exist loCs
    unsigned int getLocs(void);
};
}
#endif // CODEMETRIC_H
