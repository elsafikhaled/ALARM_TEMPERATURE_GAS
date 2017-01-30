/*
 * DIO_layer.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */

#ifndef DIO_LAYER_H_
#define DIO_LAYER_H_
#include <avr/io.h>
#include "std_data_types_EKE.h"


U8_t EKE_DIO_InitPort(U8_t portName,U8_t value);

/*********************************************************************
 * Function    : U8_t  EKE_DIO_InitPort(U8_t portName,U8_t value);
 *
 * DESCRIPTION : This function used to Initialize port.
 *
 * PARAMETERS  :
 *
 *             U8_t PortName: User write which port need to access.
 *                            like 'A' or 'a'.
 *             U8_t Value   : User write the value in range (0 -> 255).
 *
 * Return Value: The function will return -1 if user enter wrong inputs.
 *               or return 1 if OK.
 * Note        : To configure PIN as output you should set the bit mask "1"
 *               and to set PIN input you should set bit mask "0"
 ***********************************************************************/



U8_t EKE_DIO_writePort(U8_t portName,U8_t value);

/*********************************************************************
 * Function    : U8_t EKE_DIO_writePort(U8_t portName,U8_t value);
 *
 * DESCRIPTION : This function used to Initialize port.
 *
 * PARAMETERS  :
 *
 *             U8_t PortName: User write which port need to access.
 *                            like 'A' or 'a'.
 *             U8_t Value   : User write the value in range (0 -> 255).
 *
 * Return Value: The function will return -1 if user enter wrong inputs.
 *               or return 1 if OK.
 * Note        : To configure PIN as output you should set the bit mask "1"
 *               and to set PIN input you should set bit mask "0"
 ***********************************************************************/

U8_t EKE_DIO_readPort(U8_t portName);

/*********************************************************************
 * Function    : U8_t EKE_DIO_readPort(U8_t portName,U8_t value);
 *
 * DESCRIPTION : This function used to Initialize pin.
 *
 * PARAMETERS  :
 *
 *             U8_t PortName: User write which port need to access.
 *                            like 'A' or 'a'.
 *
 * Return Value: The function will return -1 if user enter wrong inputs.
 *               or return 1 if OK.
 * Note        : To configure PIN as output you should set the bit mask "1"
 *               and to set PIN input you should set bit mask "0"
 ***********************************************************************/


U8_t EKE_DIO_InitPin (U8_t PortName, U8_t PinNumber,U8_t Direction);
/*********************************************************************
* Function    : EF_B_DIO_InitPin (U8_t PortName, U8_t PinNumber,U8_t Direction)
*
* DESCRIPTION : This function used to Initialize port.
*
* PARAMETERS  :
*
*             U8_t PortName: User write which port need to access.
*                            like 'A' or 'a'.
*             U8_t PinNumber: Pin Number between 0  and 7
*
*             U8_t Direction: Either INPUT or OUTPUT
*
* Return Value: The function will return -1 if user enter wrong inputs.
*               or return 1 if OK.
* Note        : Nothing
**********************************************************************/

U8_t EKE_DIO_setPin (U8_t PortName, U8_t PinNumber);


/*********************************************************************
 * Function    :  U8_t EKE_DIO_setPin (U8_t PortName, U8_t PinNumber);
 *
 * DESCRIPTION : This function used to set  pin  high 1.
 *
 * PARAMETERS  :
 *
 *             U8_t PortName: User write which port need to access.
 *                            like 'A' or 'a'.
 *             PinNumber    :  0 >>>>>>>>>>>  7
 * Return Value: The function will return -1 if user enter wrong inputs.
 *               or return 1 if OK.
 * Note        : Nothing
 ***********************************************************************/

U8_t EKE_DIO_clearPin (U8_t PortName, U8_t PinNumber);

/*********************************************************************
 * Function    : U8_t EKE_DIO_clearPin (U8_t PortName, U8_t PinNumber);
 *
 * DESCRIPTION : This function used to clear  pin to 0.
 *
 * PARAMETERS  :
 *
 *             U8_t PortName: User write which port need to access.
 *                            like 'A' or 'a'.
 *             PinNumber    :  0>>>>>>>>>>>>>>7
 *
 * Return Value: The function will return -1 if user enter wrong inputs.
 *               or return 1 if OK.
 * Note        : Nothing
 ************************************************************************/


















#endif /* DIO_LAYER_H_ */
