/*
 * DIO_prog.c
 *
 *  Created on: Jul 15, 2023
 *      Author: Raghad Islam
 */

#include "../../SERVICE/STDTypes.h"
#include "../../SERVICE/errorState.h"

#include "DIO_priv.h"
#include "DIO_config.h"

/*
 * @brief initializaion function to set the initial direction of all DIO pins.
 * @return error statues
 */
ES_t DIO_enuInit(void){

	ES_t Local_enuErrorState = ES_NOK;
	
	/* initialize the DDR registers */
	DDRA = CONC(PA_PIN7_DIR , PA_PIN6_DIR , PA_PIN5_DIR , PA_PIN4_DIR , PA_PIN3_DIR , PA_PIN2_DIR, PA_PIN1_DIR, PA_PIN0_DIR);
	DDRB = CONC(PB_PIN7_DIR , PB_PIN6_DIR , PB_PIN5_DIR , PB_PIN4_DIR , PB_PIN3_DIR , PB_PIN2_DIR, PB_PIN1_DIR, PB_PIN0_DIR);
	DDRC = CONC(PC_PIN7_DIR , PC_PIN6_DIR , PC_PIN5_DIR , PC_PIN4_DIR , PC_PIN3_DIR , PC_PIN2_DIR, PC_PIN1_DIR, PC_PIN0_DIR);
	DDRD = CONC(PD_PIN7_DIR , PD_PIN6_DIR , PD_PIN5_DIR , PD_PIN4_DIR , PD_PIN3_DIR , PD_PIN2_DIR, PD_PIN1_DIR, PD_PIN0_DIR);

	/* initialize the PORT registers */
	PORTA = CONC(PA_PIN7_VAL , PA_PIN6_VAL , PA_PIN5_VAL , PA_PIN4_VAL , PA_PIN3_VAL , PA_PIN2_VAL, PA_PIN1_VAL, PA_PIN0_VAL);
	PORTB = CONC(PB_PIN7_VAL , PB_PIN6_VAL , PB_PIN5_VAL , PB_PIN4_VAL , PB_PIN3_VAL , PB_PIN2_VAL, PB_PIN1_VAL, PB_PIN0_VAL);
	PORTC = CONC(PC_PIN7_VAL , PC_PIN6_VAL , PC_PIN5_VAL , PC_PIN4_VAL , PC_PIN3_VAL , PC_PIN2_VAL, PC_PIN1_VAL, PC_PIN0_VAL);
	PORTD = CONC(PD_PIN7_VAL , PD_PIN6_VAL , PD_PIN5_VAL , PD_PIN4_VAL , PD_PIN3_VAL , PD_PIN2_VAL, PD_PIN1_VAL, PD_PIN0_VAL);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}


/*
 * @brief function to set the chosen direction of the entire DIO port.
 * @param[in]   Copy_u8PortID:	1- DIO_u8PORTA
 *								2- DIO_u8PORTB
 * 								3- DIO_u8PORTC
 *								4- DIO_u8PORTD
 *
 * @param[in]   Copy_u8Val:	desired direction for all pins of the desired port.
 * @return error statues
 */
ES_t DIO_enuSetPortDir (u8 Copy_u8PortID , u8 Copy_u8Val ){

	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PortID <= DIO_PORTD)
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA :
			DDRA = Copy_u8Val;
			break;
		case DIO_PORTB :
			DDRB = Copy_u8Val;
			break;
		case DIO_PORTC :
			DDRC = Copy_u8Val;
			break;
		case DIO_PORTD :
			DDRD = Copy_u8Val;
			break;
		}
		Local_enuErrorState = ES_OK;

	}
	else Local_enuErrorState = ES_OUT_OF_RANGE;


	return Local_enuErrorState;
}


/*
 * @brief function to set the value of the entire DIO port.
 * @param[in]   Copy_u8PortID:	1- DIO_u8PORTA
 *								2- DIO_u8PORTB
 * 								3- DIO_u8PORTC
 *								4- DIO_u8PORTD
 *
 * @param[in]   Copy_u8Val:	desired value for all pins of the desired port.
 * @return error statues
 */
ES_t DIO_enuSetPortVal( u8 Copy_u8PortID , u8 Copy_u8Val ){

	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PortID <= DIO_PORTD)
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA :
			PORTA = Copy_u8Val;
			break;
		case DIO_PORTB :
			PORTB = Copy_u8Val;
			break;
		case DIO_PORTC :
			PORTC = Copy_u8Val;
			break;
		case DIO_PORTD :
			PORTD = Copy_u8Val;
			break;
		}

		Local_enuErrorState = ES_OK;
	}
	else Local_enuErrorState = ES_OUT_OF_RANGE;

	return Local_enuErrorState;
}


/*
 * @brief function to toggle the value of the entire DIO port.
 * @param[in]   Copy_u8PortID:	1- DIO_u8PORTA
 *								2- DIO_u8PORTB
 * 								3- DIO_u8PORTC
 *								4- DIO_u8PORTD
 * @return error statues
 */
ES_t DIO_enuTogglePort( u8 Copy_u8PortID ){

	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8PortID <= DIO_PORTD)
	{
		switch(Copy_u8PortID)
		{
		case DIO_PORTA :
			PORTA = ~PORTA;
			break;
		case DIO_PORTB :
			PORTB = ~PORTB;
			break;
		case DIO_PORTC :
			PORTC = ~PORTC;
			break;
		case DIO_PORTD :
			PORTD = ~PORTD;
			break;
		}

		Local_enuErrorState = ES_OK;
	}
	else Local_enuErrorState = ES_OUT_OF_RANGE;


	return Local_enuErrorState;
}


/*
 * @brief function to read the value of the entire DIO port.
 * @param[in]   Copy_u8PortID:	1- DIO_u8PORTA
 *								2- DIO_u8PORTB
 * 								3- DIO_u8PORTC
 *								4- DIO_u8PORTD
 *
 * @param[out]   Copy_pu8Val:	the desired port reading.
 * @return error statue
 */
ES_t DIO_enuGetPortVal( u8 Copy_u8PortID , u8* Copy_pu8Val ){

	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pu8Val != NULL)
	{
		if(Copy_u8PortID <= DIO_PORTD)
		{
			switch(Copy_u8PortID)
			{
			case DIO_PORTA :
				*Copy_pu8Val = PINA;
				break;
			case DIO_PORTB :
				*Copy_pu8Val = PINB;
				break;
			case DIO_PORTC :
				*Copy_pu8Val = PINC;
				break;
			case DIO_PORTD :
				*Copy_pu8Val = PIND;
				break;
			}

			Local_enuErrorState = ES_OK;
		}
		else Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	else Local_enuErrorState = ES_NULL_POINTER;


	return Local_enuErrorState;
}


/*
 * @brief function to set the chosen direction of the DIO pin.
 *
 * @param[in]   Copy_u8PortID:	1- DIO_u8PORTA
 *								2- DIO_u8PORTB
 * 								3- DIO_u8PORTC
 *								4- DIO_u8PORTD
 *
 * @param[in]	Copy_u8PinID: 	1- DIO_u8PIN0
 *				              	2- DIO_u8PIN1
 *				              	3- DIO_u8PIN2
 *				              	4- DIO_u8PIN3
 *				              	5- DIO_u8PIN4
 *				              	6- DIO_u8PIN5
 *				              	7- DIO_u8PIN6
 *				              	8- DIO_u8PIN7
 *
 * @param[in]   Copy_u8Val:		1- DIO_u8OUTPUT
 * 								2- DIO_u8INPUT
 * @return error statues
 */
ES_t DIO_enuSetPinDir( u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Val ){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <= DIO_PIN7 && Copy_u8Val <= OUTPUT )
	{

		switch(Copy_u8PortID)
		{
		case DIO_PORTA :
			DDRA &= ~(DIO_MASK_BIT << Copy_u8PinID);
			DDRA |=  (Copy_u8Val << Copy_u8PinID);
			break;
		case DIO_PORTB :
			DDRB &= ~(DIO_MASK_BIT << Copy_u8PinID);
			DDRB |=  (Copy_u8Val << Copy_u8PinID);
			break;
		case DIO_PORTC :
			DDRC &= ~(DIO_MASK_BIT << Copy_u8PinID);
			DDRC |=  (Copy_u8Val << Copy_u8PinID);
			break;
		case DIO_PORTD :
			DDRD &= ~(DIO_MASK_BIT << Copy_u8PinID);
			DDRD |=  (Copy_u8Val << Copy_u8PinID);
			break;
		}

		Local_enuErrorState = ES_OK;

	}
	else Local_enuErrorState = ES_OUT_OF_RANGE;

	return Local_enuErrorState;
}


/*
 * @brief function to set the chosen value of the DIO pin.
 * @param[in]   Copy_u8PortID:	1- DIO_u8PORTA
 *								2- DIO_u8PORTB
 * 								3- DIO_u8PORTC
 *								4- DIO_u8PORTD
 *
 * @param[in]	Copy_u8PinID: 	1- DIO_u8PIN0
 *				              	2- DIO_u8PIN1
 *				              	3- DIO_u8PIN2
 *				              	4- DIO_u8PIN3
 *				              	5- DIO_u8PIN4
 *				              	6- DIO_u8PIN5
 *				              	7- DIO_u8PIN6
 *				              	8- DIO_u8PIN7
 *
 * @param[in]   Copy_u8Val:		1- DIO_u8HIGH
 * 								2- DIO_u8LOW
 * @return error statues
 */
ES_t DIO_enuSetPinVal( u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Val ){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <= DIO_PIN7 && Copy_u8Val <= OUTPUT )
	{

		switch(Copy_u8PortID)
		{
		case DIO_PORTA :
			PORTA &= ~(DIO_MASK_BIT << Copy_u8PinID);
			PORTA |=  (Copy_u8Val << Copy_u8PinID);
			break;
		case DIO_PORTB :
			PORTB &= ~(DIO_MASK_BIT << Copy_u8PinID);
			PORTB |=  (Copy_u8Val << Copy_u8PinID);
			break;
		case DIO_PORTC :
			PORTC &= ~(DIO_MASK_BIT << Copy_u8PinID);
			PORTC |=  (Copy_u8Val << Copy_u8PinID);
			break;
		case DIO_PORTD :
			PORTD &= ~(DIO_MASK_BIT << Copy_u8PinID);
			PORTD |=  (Copy_u8Val << Copy_u8PinID);
			break;
		}

		Local_enuErrorState = ES_OK;

	}
	else Local_enuErrorState = ES_OUT_OF_RANGE;

	return Local_enuErrorState;
}


/*
 * @brief function to toggle the value of the DIO pin.
 * @param[in]   Copy_u8PortID:	1- DIO_u8PORTA
 *								2- DIO_u8PORTB
 * 								3- DIO_u8PORTC
 *								4- DIO_u8PORTD
 *
 * @param[in]	Copy_u8PinID: 	1- DIO_u8PIN0
 *				              	2- DIO_u8PIN1
 *				              	3- DIO_u8PIN2
 *				              	4- DIO_u8PIN3
 *				              	5- DIO_u8PIN4
 *				              	6- DIO_u8PIN5
 *				              	7- DIO_u8PIN6
 *				              	8- DIO_u8PIN7
 * @return error statues
 */
ES_t DIO_enuTogglePin( u8 Copy_u8PortID , u8 Copy_u8PinID  ){

	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <= DIO_PIN7 )
	{

		switch(Copy_u8PortID)
		{
		case DIO_PORTA :
			PORTA ^= (DIO_MASK_BIT << Copy_u8PinID);
			break;
		case DIO_PORTB :
			PORTB ^= (DIO_MASK_BIT << Copy_u8PinID);
			break;
		case DIO_PORTC :
			PORTC ^= (DIO_MASK_BIT << Copy_u8PinID);
			break;
		case DIO_PORTD :
			PORTD ^= (DIO_MASK_BIT << Copy_u8PinID);
			break;
		}

		Local_enuErrorState = ES_OK;

	}
	else Local_enuErrorState = ES_OUT_OF_RANGE;

	return Local_enuErrorState;
}


/*
 * @brief function to read the value of the DIO pin.
 *
 * @param[in]   Copy_u8PortID:	1- DIO_u8PORTA
 *								2- DIO_u8PORTB
 * 								3- DIO_u8PORTC
 *								4- DIO_u8PORTD
 *
 *				Copy_u8PinID: 	1- DIO_u8PIN0
 *				              	2- DIO_u8PIN1
 *				              	3- DIO_u8PIN2
 *				              	4- DIO_u8PIN3
 *				              	5- DIO_u8PIN4
 *				              	6- DIO_u8PIN5
 *				              	7- DIO_u8PIN6
 *				              	8- DIO_u8PIN7
 *
 * @param[out]   Copy_pu8Val:	the desired port reading.
 *
 * @return error statues
 */
ES_t DIO_enuGetPinVal( u8 Copy_u8PortID , u8 Copy_u8PinID , u8* Copy_pu8Val ){

	ES_t Local_enuErrorState = ES_NOK;


	if(Copy_pu8Val != NULL)
	{
		if( Copy_u8PortID <= DIO_PORTD && Copy_u8PinID <= DIO_PIN7 )
		{
			switch(Copy_u8PortID)
			{
			case DIO_PORTA :
				*Copy_pu8Val = (PINA>>Copy_u8PinID) & DIO_MASK_BIT;
				break;
			case DIO_PORTB :
				*Copy_pu8Val = (PINB>>Copy_u8PinID) & DIO_MASK_BIT;
				break;
			case DIO_PORTC :
				*Copy_pu8Val = (PINC>>Copy_u8PinID) & DIO_MASK_BIT;
				break;
			case DIO_PORTD :
				*Copy_pu8Val = (PIND>>Copy_u8PinID) & DIO_MASK_BIT;
				break;
			}

			Local_enuErrorState = ES_OK;
		}
		else Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	else Local_enuErrorState = ES_NULL_POINTER;

	return Local_enuErrorState;
}

