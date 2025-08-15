/*
 * KP.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Admin
 */

#ifndef HAL_KP_KP_H_
#define HAL_KP_KP_H_

#define KP_NOT_PRESSED  255
#define KP_PRESSED      0


void KP_Init       (u8 KP_Port ) ;
u8   KP_GetValue (u8 KP_Port ) ;

#endif /* HAL_KP_KP_H_ */
