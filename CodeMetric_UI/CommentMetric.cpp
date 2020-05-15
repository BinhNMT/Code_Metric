/*
 * CommentMetric.cpp
 *
 *  Created on: Apr 15, 2020
 *      Author: BinhNMT
 *      Email: binhmainguyen193@gmail.com
 */

#include <iostream>
#include "CommentMetric.h"
#include "CodeMetric.h"

bool C_M::CommentMetric::checkTwinSlashCmt(int pos, string codeString)
{
    if(pos == 0)
    {
        return ISCMT;
    }

    // Check whether exist available code before the commented text
    else if(pos > 0)
    {
        for(int i = 0; i < pos; i++)
        {
            if(codeString[i] != '\t' && codeString[i] != ' ')
            {
                return NOTCMT;
            }
        }
    }

    return ISCMT;
}

bool C_M::CommentMetric::checkBlockCmt(int pos, string codeString)
{
    blockCmt = true;

    // Check the presence of finish character of block comments
    if ((int)codeString.find("*/") != -1)
    {
        blockCmt = false;
    }

    if (pos == 0)
    {
        return ISCMT;
    }

    // Check whether exist available code before the commented text
    else if (pos > 0)
    {
        for(int i = 0; i < pos; i++)
        {
            if(codeString[i] != '\t' && codeString[i] != ' ')
            {
                return NOTCMT;
            }
        }
    }

    return ISCMT;
}

void C_M::CommentMetric::setFlagToDefault(void)
{
    blockCmt = false;
}

bool C_M::CommentMetric::checkCmtCode(string codeString)
{
    int pos;

    // Check whether it is a block of comments
    pos = codeString.find("/*");
    if(pos > -1 || blockCmt == true)
    {
        return checkBlockCmt(pos, codeString);
    }

    // Check whether it is a twin slash comment
    pos = codeString.find("//");
    if(pos > -1)
    {
        return checkTwinSlashCmt(pos, codeString);
    }

    return NOTCMT;
}
