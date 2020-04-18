/*
 * CodeMetric.h
 *
 *  Created on: Apr 11, 2020
 *      Author: BinhNMT
 *      Email: binhmainguyen193@gmail.com
 */

#ifndef CODEMETRIC_H_
#define CODEMETRIC_H_

#include <string>
using namespace std;

#define NOTCMT      0
#define ISCMT       1
#define BLOCK       2

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

    class CodeMetric: public CommentMetric
    {
        private:
            /* properties */
            unsigned int elocs;
            unsigned int totalLocs;
            unsigned int totalLines;

            // @brief   : counting number of effect LOCs
            // @param   : a line of input source code
            // @return : true       - empty line
            //           fasle      - not an empty line
            bool checkEmptyLine(string);
        
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

    class EffortMetric
    {
        private:
            float manday;

        public:
            /* class constructor */
            EffortMetric();

            // @brief   : do estimating effort (manday)
            // @param   : - elocs per day
            //            - total elocs
            void estimateEffort(unsigned int, unsigned int);
            
            // @brief   : get effort estimated result (manday value)
            // @return  : total effort (manday)
            float getManday();
    };
}

#endif /* CodeMETRIC_H_ */
