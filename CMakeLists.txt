#THIS FILE IS AUTO GENERATED FROM THE TEMPLATE! DO NOT CHANGE!
set( CMAKE_SYSTEM_NAME Generic )
set( CMAKE_SYSTEM_VERSION 1 )
cmake_minimum_required( VERSION 3.19 )

# specify cross compilers and tools
set( CMAKE_C_COMPILER arm-none-eabi-gcc )
set( CMAKE_CXX_COMPILER arm-none-eabi-g++ )
set( CMAKE_ASM_COMPILER arm-none-eabi-gcc )
set( CMAKE_AR arm-none-eabi-ar )
set( CMAKE_OBJCOPY arm-none-eabi-objcopy )
set( CMAKE_OBJDUMP arm-none-eabi-objdump )
set( SIZE arm-none-eabi-size )
set( CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY )

# project settings
project( kvadro C CXX ASM )
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_C_STANDARD 11 )

add_compile_options( -mcpu=cortex-m4 -mthumb -mthumb-interwork )
add_compile_options( -ffunction-sections -fdata-sections -fno-common -fmessage-length=0 )

add_compile_options( -O2 )
add_definitions( -DUSE_HAL_DRIVER -DSTM32F407xx )

set( DEFAULT_HEADERS 17 )

set( SOURCE_DIR src )
set( MAIN_DIR ${SOURCE_DIR}/main )
set( DEVICES_DIR ${SOURCE_DIR}/devices )
set( PERIPHERY_DIR ${SOURCE_DIR}/periphery )
set( STARTUP_DIR ${SOURCE_DIR}/startup/ )

file( GLOB_RECURSE SOURCES "${DEVICES_DIR}/*.*" "${MAIN_DIR}/*.*" "${PERIPHERY_DIR}/*.*" "${STARTUP_DIR}/*.s" )

include_directories( ${SOURCE_DIR} )
set( LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F407VGTx_FLASH.ld )

add_link_options( -Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map )
add_link_options( -mcpu=cortex-m4 -mthumb -mthumb-interwork )
add_link_options( -T ${LINKER_SCRIPT} )
add_link_options( -specs=nosys.specs -specs=nano.specs -T ${LINKER_SCRIPT} )
add_executable( ${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT} ${MAIN} )
