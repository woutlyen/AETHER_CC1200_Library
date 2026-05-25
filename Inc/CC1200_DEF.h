/**
  ******************************************************************************
  * @file    CC1200_DEF.h
  * @author  Wout Lyen
  * @brief   This file contains the defines for the CC1200
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

/* SPI flags */
#define CC1200_READ_Pos         (7U)
#define CC1200_READ_Msk         (0x1 << CC1200_READ_Pos)                    /*!< 0b10000000     */
#define CC1200_READ             CC1200_READ_Msk                             /*!< CC1200 Read    */

#define CC1200_BURST_Pos        (6U)
#define CC1200_BURST_Msk        (0x1 << CC1200_BURST_Pos)                   /*!< 0b01000000     */
#define CC1200_BURST            CC1200_BURST_Msk                            /*!< CC1200 Burst   */

#define CC1200_SINGLE_WRITE     0x00
#define CC1200_BURST_WRITE      CC1200_BURST
#define CC1200_SINGLE_READ      CC1200_READ
#define CC1200_BURST_READ       (CC1200_READ | CC1200_BURST)
#define CC1200_EXTENDED_ADDR    0x2F
#define CC1200_MAX_NORM_ADDR    0x2E

/* TX/RX FIFO */
#define CC1200_FIFO       0x3F
#define CC1200_TXFIFO     CC1200_FIFO
#define CC1200_RXFIFO     CC1200_FIFO