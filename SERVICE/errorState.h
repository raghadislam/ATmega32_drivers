/*
 * errorState.h
 *
 *  Created on: Jul 15, 2023
 *      Author: Raghad Islam
 */

#ifndef ERRORSTATE_H_
#define ERRORSTATE_H_

/* enum to define all error types needed */
typedef enum{
	ES_NOK,
	ES_OK,
	ES_NULL_POINTER,
	ES_OUT_OF_RANGE,
	ES_WRONG_TYPE,
	ES_PIN_NOT_CONNECTED,
	ES_WEONG_PIN,
	ES_UNSUPPORTED_MODE,
	ES_TIME_OUT,
	ES_BUSY_STATE,
	ES_RESERVED_ADDRESSES,
	ES_START_COND,
	ES_REP_START_COND,
	ES_SLAVE_ADD_WITH_WR,
	ES_SLAVE_ADD_WITH_RD,
	ES_MASTER_WR_BYTE,
	ES_MASTER_RD_BYTE

}ES_t;

#endif /* ERRORSTATE_H_ */
