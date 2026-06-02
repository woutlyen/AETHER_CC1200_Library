/**
  ******************************************************************************
  * @file    CC1200.h
  * @author  Wout Lyen
  * @brief   This file contains the headers of the CC1200 functions.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 Aetherspace.
  * All rights reserved.
  *
  * This software is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef CC1200_H
#define CC1200_H

#ifdef __cplusplus
extern "C" {
#endif

/** 
 * Change this include to the STM32 HAL include for your specific MCU
 */
#include "stm32f7xx_hal.h"

#include "cmsis_os2.h"

#include <stdbool.h>

/* Chip Status Byte */
#define CC1200_STATUS_CHIP_RDY_Pos    (7U)
#define CC1200_STATUS_CHIP_RDY_Msk    (0x1 << CC1200_STATUS_CHIP_RDY_Pos)   /*!< 0b10000000   */
#define CC1200_STATUS_CHIP_RDY        CC1200_STATUS_CHIP_RDY_Msk            /*!< CC1200 Chip Ready */

#define CC1200_STATUS_STATE_Pos         (4U)
#define CC1200_STATUS_STATE_IDLE        (0x0 << CC1200_STATUS_STATE_Pos)    /*!< 0b00000000   IDLE state        */
#define CC1200_STATUS_STATE_RX          (0x1 << CC1200_STATUS_STATE_Pos)    /*!< 0b00010000   Receive state     */
#define CC1200_STATUS_STATE_TX          (0x2 << CC1200_STATUS_STATE_Pos)    /*!< 0b00100000   Transmit state    */
#define CC1200_STATUS_STATE_FSTXON      (0x3 << CC1200_STATUS_STATE_Pos)    /*!< 0b00110000   Fast TX ready     */
#define CC1200_STATUS_STATE_CALIBRATE   (0x4 << CC1200_STATUS_STATE_Pos)    /*!< 0b01000000   Frequency synthesizer calibration is running */
#define CC1200_STATUS_STATE_SETTLING    (0x5 << CC1200_STATUS_STATE_Pos)    /*!< 0b01010000   PLL is settling   */
#define CC1200_STATUS_STATE_RXFIFO_ERR  (0x6 << CC1200_STATUS_STATE_Pos)    /*!< 0b01100000   RX FIFO has over/underflowed. Read out any useful data, then flush the FIFO with an SFRX strobe*/
#define CC1200_STATUS_STATE_TXFIFO_ERR  (0x7 << CC1200_STATUS_STATE_Pos)    /*!< 0b01110000   TX FIFO has over/underflowed. Flush the FIFO with an SFTX strobe*/
#define CC1200_STATUS_STATE_Msk         (0x7 << CC1200_STATUS_STATE_Pos)    /*!< 0b01110000   */

#define CC1200_STATUS_RESERVED_Msk       (0xF << 0)                         /*!< 0b00001111   Reserved bits in the status byte */

typedef enum {
    CC1200_867_999878_MHz_4_GFSK_250_KSPS,
    CC1200_867_999878_MHz_2_GFSK_38_4_KSPS
} CC1200_Config;

typedef enum {
    CC1200_RX_OFF_MODE_IDLE = 0b00,
    CC1200_RX_OFF_MODE_FSTXON = 0b01,
    CC1200_RX_OFF_MODE_TX = 0b10,
    CC1200_RX_OFF_MODE_RX = 0b11
} CC1200_RXOffMode;

typedef enum {
    CC1200_FS_AUTOCAL_NEVER = 0b00,
    CC1200_FS_AUTOCAL_IDLE_TO_RXTX = 0b01,
    CC1200_FS_AUTOCAL_RXTX_TO_IDLE = 0b10,
    CC1200_FS_AUTOCAL_4_RXTX_TO_IDLE = 0b11
} CC1200_FSAautocal;

/* Function prototypes */
void CC1200_SetSPIHandle(SPI_HandleTypeDef *hspi, GPIO_TypeDef *CSPort, uint32_t CSPin, GPIO_TypeDef *miso_port, uint32_t miso_pin, uint32_t spi_rxtx_cplt_flg);

void CC1200_SetAllInterruptFlags(uint32_t pkt_sync_rxtx_re_flg, uint32_t pkt_sync_rxtx_fe_flg, uint32_t rx_fifo_thr_re_flg, uint32_t tx_fifo_thr_fe_flg);
void CC1200_SetRXInterruptFlags(uint32_t pkt_sync_rxtx_re_flg, uint32_t pkt_sync_rxtx_fe_flg, uint32_t rx_fifo_thr_re_flg);
void CC1200_SetTXInterruptFlags(uint32_t pkt_sync_rxtx_fe_flg, uint32_t tx_fifo_thr_fe_flg);

void CC1200_Init(CC1200_Config config);

void CC1200_SetRXOffMode(CC1200_RXOffMode mode);
void CC1200_SetFSAutocal(CC1200_FSAautocal autoccal);

void CC1200_TransmitPacket(uint8_t *data, uint8_t length);
bool CC1200_ReceivePacket(uint8_t *currentBuffer, uint16_t spaceLeft, uint8_t *nextBuffer);

uint8_t CC1200_GetState(void);

#ifdef __cplusplus
}
#endif

#endif /* CC1200_H */