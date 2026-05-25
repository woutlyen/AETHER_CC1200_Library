# AETHER_CC1200_Library

A comprehensive HAL-based driver library for the **CC1200 sub-GHz RF transceiver** on STM32 microcontrollers. This library provides a high-level API for configuring and communicating with the CC1200 chip via SPI.

## Features

- **SPI Communication**: Full-duplex SPI interface for register access and FIFO operations
- **Packet Transmission & Reception**: Easy-to-use functions for transmitting and receiving RF packets
- **Register Access**: Read and write to both normal and extended register addresses
- **State Management**: Monitor and control chip operating states (IDLE, RX, TX, etc.)
- **Command Strobes**: Support for all CC1200 command strobes (reset, calibration, TX/RX control, etc.)
- **FIFO Management**: TX/RX FIFO handling with overflow/underflow detection
- **CMake Integration**: Ready for integration with STM32CubeMX projects

## Hardware Requirements

- **MCU**: STM32 microcontroller (default: **STM32F7** series)
- **RF Chip**: Texas Instruments CC1200 sub-GHz transceiver

## Installation

1. Add this repository as a git submodule to your STM32 project:
   ```bash
   git submodule add <repo-url> AETHER_CC1200_Library
   git submodule update --init --recursive
   ```

2. Add the submodule to your `CMakeLists.txt`:
   ```cmake
   # Add user defined libraries
   add_subdirectory(AETHER_CC1200_Library)

   # Link the library
   target_link_libraries(${CMAKE_PROJECT_NAME}
       stm32cubemx
       AETHER_CC1200
   )
   ```

3. Ensure your STM32CubeMX HAL is available in your project (generated via `cmake/stm32cubemx` or similar)

## Configuration

### STM32 MCU Selection ⚠️

**IMPORTANT**: The default include header is configured for **STM32F7** microcontrollers (`stm32f7xx_hal.h`). If you are using a different STM32 series, you **must** update the include in `Inc/CC1200.h`:

```c
// Default (STM32F7)
#include "stm32f7xx_hal.h"

// Change to your MCU series:
// #include "stm32h7xx_hal.h"   // for STM32H7
// #include "stm32l4xx_hal.h"   // for STM32L4
// #include "stm32g4xx_hal.h"   // for STM32G4
// etc.
```

## API Reference

### Initialization Functions (Mandatory)

- `CC1200_SetSPIHandle(SPI_HandleTypeDef *hspi, GPIO_TypeDef *CSPort, uint32_t CSPin)` - Configure SPI interface and chip select
- `CC1200_SetUserMISOPins(GPIO_TypeDef *miso_port, uint32_t miso_pin)` - Set MISO pin used for monitoring the state of the CC1200 inside the library
- `CC1200_Init()` - Initialize CC1200 chip

### Communication Functions

- `CC1200_CommandStrobe(uint8_t strobe)` - Send a command strobe (RESET, RX, TX, IDLE, etc.)
- `CC1200_TransmitPacket(uint8_t *data, uint8_t length)` - Transmit a packet
- `CC1200_ReceiveHeader(uint8_t *buffer)` - Read packet header
- `CC1200_ReceivePayload(uint8_t *buffer, uint8_t length)` - Read packet payload

### Status Functions

- `CC1200_GetState()` - Get current chip state

## Status Byte Format

The CC1200 returns a status byte with the following information:

```
Bit 7: CHIP_RDY    - Chip is ready (1 = ready)
Bits 6-4: STATE    - Current chip state
Bits 3-0: Reserved
```

States:
- `0x0`: IDLE
- `0x1`: RX
- `0x2`: TX
- `0x3`: FSTXON (Fast TX ready)
- `0x4`: CALIBRATE
- `0x5`: SETTLING (PLL settling)
- `0x6`: RXFIFO_ERR
- `0x7`: TXFIFO_ERR

## Troubleshooting

### Library won't compile

1. Verify the STM32 HAL include in `Inc/CC1200.h` matches your MCU
2. Ensure `stm32cubemx` CMake target is available in your project
3. Check that `cmsis_os2.h` (CMSIS-RTOS2) is available

### Communication issues

1. Verify SPI clock is properly configured (typically 10 MHz or lower)
2. Check CS pin is correctly set high before and after transfers
3. Ensure correct SPI mode is used (typically SPI Mode 0)
4. Verify CC1200 has proper power supply and decoupling capacitors

## License

Copyright (c) 2026 Aetherspace. All rights reserved.

This software is provided AS-IS.

## Author

Wout Lyen - Aetherspace
