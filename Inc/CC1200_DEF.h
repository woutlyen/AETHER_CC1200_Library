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

/* Command strobes */
#define CC1200_SRES             0x30    // Reset chip
#define CC1200_SFSTXON          0x31    // Enable and calibrate frequency synthesizer (if SETTLING_CFG.FS_AUTOCAL = 1). If in RX and PKT_CFG2.CCA_MODE ≠ 0: Go to a wait state where only the synthesizer is running (for quick RX/TX turnaround). 
#define CC1200_SXOFF            0x32    // Enter XOFF state when CSn is de-asserted
#define CC1200_SCAL             0x33    // Calibrate frequency synthesizer and turn it off. SCAL can be strobed from IDLE mode without setting manual calibration mode (SETTLING_CFG.FS_AUTOCAL = 0)
#define CC1200_SRX              0x34    // Enable RX. Perform calibration first if coming from IDLE and SETTLING_CFG.FS_AUTOCAL = 1
#define CC1200_STX              0x35    // In IDLE state: Enable TX. Perform calibration first if SETTLING_CFG.FS_AUTOCAL = 1. If in RX state and PKT_CFG2.CCA_MODE ≠ 0: Only go to TX if channel is clear
#define CC1200_SIDLE            0x36    // Exit RX / TX, turn off frequency synthesizer and exit Wake-On-Radio mode if applicable
#define CC1200_SAFC             0x37    // Automatic Frequency Compensation
#define CC1200_SWOR             0x38    // Start automatic RX polling sequence (Wake-On-Radio) as described in Section 9.6 if WOR_CFG0.RC_PD = 0 
#define CC1200_SPWD             0x39    // Enter SLEEP mode when CSn is de-asserted
#define CC1200_SFRX             0x3A    // Flush the RX FIFO. Only issue SFRX in IDLE or RX_FIFO_ERR states
#define CC1200_SFTX             0x3B    // Flush the TX FIFO. Only issue SFTX in IDLE or TX_FIFO_ERR states
#define CC1200_SWORRST          0x3C    // Reset the eWOR timer to the Event1 value
#define CC1200_SNOP             0x3D    // No operation. May be used to get access to the chip status byte