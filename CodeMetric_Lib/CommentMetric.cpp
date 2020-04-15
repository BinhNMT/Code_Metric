/*
 * CommentMetric.cpp
 *
 *  Created on: Apr 15, 2020
 *      Author: BinhNMT
 */

#include <iostream>
#include <string.h>
#include "CodeMetric.h"
using namespace C_M;

unsigned int CommentMetric::verifyComment(int pos, string codeString)
{
    // Check whether it is a twin slash comment or not
    if(codeString[pos + 1] == '/')
    {
        return SLASHCMT;
    }

    // Check whether it is a block comment or not
    else if(codeString[pos + 1] == '*')
    {
        return BLOCKCMT;
    }
    
    return NOTCMT;
}

bool CommentMetric::checkTwinSlashCmt(int pos, string codeString)
{
    unsigned int notComment = 0;
    
    if(pos == 0)
    {
        return true;
    }

    // Check whether exist available code before the commented text or not
    else if(pos > 0)
    {
        for(int i = 0; i < pos; i++)
        {
            if(codeString[i] != '\t' && codeString[i] != ' ')
            {
                notComment++;
            }
        }

        if(notComment)
        {
            return false;
        }
    }
    
    return true;
}

bool CommentMetric::checkBlockCmt(int pos, string codeString)
{
    // Not implemented yet
    // @default: return false
    return false;
}

bool CommentMetric::checkCmtCode(int pos, string codeString)
{
    unsigned int verify;
    verify = verifyComment(pos, codeString);

    if(verify == 0)
    {
        return false;
    }

    else if(verify == SLASHCMT)
    {
        return checkTwinSlashCmt(pos, codeString);
    }

    else
    {
        return checkBlockCmt(pos, codeString);
    }
}