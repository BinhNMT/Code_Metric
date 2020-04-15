/*
 * CodeMetric.h
 *
 *  Created on: Apr 11, 2020
 *      Author: BinhNMT
 */

#ifndef CODEMETRIC_H_
#define CODEMETRIC_H_

#include <string>
using namespace std;

#define NOTCMT      0
#define SLASHCMT    1
#define BLOCKCMT    2

namespace C_M
{
    class CommentMetric 
    {
        private:
            // @brief  : Verify the doubt code is a comment or not
            // @param  : pos        - position of slash was detected
            //           codeString - a line of input source code
            // @return : NOTCMT     - not a comment code
            //           SLASHCMT   - a commented code with twin slash type
            //           BLOCKCMT   - a commented code with block comment type
            unsigned int verifyComment(int, string);
            
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
            // @brief  : Verify the doubt code is a comment or not
            // @param  : pos        - position of slash was detected
            //           codeString - a line of input source code
            // @return : true       - commented code
            //           fasle      - not a commented code
            bool checkCmtCode(int, string);
    };

    class CodeMetric: public CommentMetric
    {
        private:
            /* properties */
            unsigned int elocs;
            unsigned int locs;
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
            
            // @brief   : get exist Line of Code values
            // @return  : number of exist loCs
            unsigned int getLocs(void);
            
            // @brief   : get total Line of Code values
            // @return  : number of total loCs
            unsigned int getLines(void);
    };
}

#endif /* CodeMETRIC_H_ */
