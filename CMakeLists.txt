file(GLOB AETHER_CC1200_SOURCES
    Src/*.c
)

add_library(AETHER_CC1200 STATIC
    ${AETHER_CC1200_SOURCES}
)

target_include_directories(AETHER_CC1200 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

# Give the library access to STM32 HAL headers
target_link_libraries(AETHER_CC1200 PUBLIC stm32cubemx)