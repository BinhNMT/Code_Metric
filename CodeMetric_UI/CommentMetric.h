/*
 * CommentMetric.h
 *
 *  Created on: Apr 11, 2020
 *      Author: BinhNMT
 *      Email: binhmainguyen193@gmail.com
 */
#ifndef COMMENTMETRIC_H
#define COMMENTMETRIC_H

#include <string>
using namespace  std;

namespace C_M
{
class CommentMetric
{
private:
    // @brief  : a flag that used to notice in a block comments
    // @detail : - True in case of in a block comments
    //         : - False in case of not in a block comments
    bool blockCmt;

    // @brief  : Verify the doubt code is a comment with twin slash type or not
    // @param  : pos        - position of slash was detected
    //           codeString - a line of input source code
    // @return : true       - commented code
    //           fasle      - not a commented code
    bool checkTwinSlashCmt(int, string);

    // @brief  : Verify the doubt code is a comment with block comment type or not
    // @param  : pos        - position of slash was detected
    //           codeString - a line of input source code
    // @return : true       - commented code
    //           fasle      - not a commented code
    bool checkBlockCmt(int, string);

public:
    // @brief  : set the default value for blockCmt flag is zero
    void setFlagToDefault(void);

    // @brief  : Verify the doubt code is a comment or not
    // @param  : pos        - position of slash was detected
    //           codeString - a line of input source code
    // @return : 0       - not a commented code
    //           1       - commented code
    //           2       - block commented code
    bool checkCmtCode(string);
};
}
#endif // COMMENTMETRIC_H
