/*
 * EffortMetric.h
 *
 *  Created on: Apr 24, 2020
 *      Author: BinhNMT
 */

#ifndef EFFORTMETRIC_H_
#define EFFORTMETRIC_H_

namespace C_M
{
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

#endif /* EFFORTMETRIC_H_ */
