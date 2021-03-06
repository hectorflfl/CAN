/*
 * CAN.h
 *
 *  Created on: 24/03/2019
 *      Author: Cognati
 */

#ifndef CAN_H_
#define CAN_H_

#include "S32K144.h"

typedef enum{myCAN0
			,myCAN1
			,myCAN2
}myCANType;

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN0 base address */
#define CAN0_BASE                                (0x40024000u)
/** Peripheral CAN0 base pointer */
#define CAN0                                     ((CAN_Type *)CAN0_BASE)
/** Peripheral CAN1 base address */
#define CAN1_BASE                                (0x40025000u)
/** Peripheral CAN1 base pointer */
#define CAN1                                     ((CAN_Type *)CAN1_BASE)
/** Peripheral CAN2 base address */
#define CAN2_BASE                                (0x4002B000u)
/** Peripheral CAN2 base pointer */
#define CAN2                                     ((CAN_Type *)CAN2_BASE)

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 \brief
 This function initialize CAN protocol with standard values
 \param[in] CAN_base
 \param[in] id_Rx to configure the receiver id
 \param[in] Configure the frecuency
 \return void
 */
void init_CAN(uint8_t CAN_base, uint16_t id_Rx, uint64_t frecuency);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 \brief
 This function transmits a frame of CAN, which you are able to set the ID, DLC, and the data that is going to be transmitted
 \param[in] CAN_Type *can_selected
 \param[in] uint16_t id_standar
 \param[in] uint8_t DLC
 \param[in] uint32_t word1
 \param[in] uint32_t word2
 \return void
 */
void transmit_CAN(CAN_Type *can_selected, uint16_t id_standar,uint8_t DLC,uint32_t word1,uint32_t word2);

/*!
 \brief
 This function can receive a frame of a CAN and store the DLC, CODE, DATA, ID in the address locations of the variables that were passed
 \param[in] CAN_Type *can_pointer
 \param[out] uint32_t*RxCODE
 \param[out] uint32_t*ID
 \param[out] uint32_t* DLC
 \param[out] uint32_t* Rx_DATA
 \return void
 */
void receive_CAN(CAN_Type *can_pointer,uint32_t*RxCODE,uint32_t*ID,uint32_t* DLC, uint32_t* Rx_DATA);



#endif /* CAN_H_ */
