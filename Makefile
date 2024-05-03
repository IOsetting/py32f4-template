##### Project #####

PROJECT			?= app
# The path for generated files
BUILD_DIR		= Build

# MCU types: 
#   PY32F403xD
MCU_TYPE		= PY32F403xD

##### Options #####

# Programmer, jlink or pyocd
FLASH_PROGRM	?= pyocd

##### Toolchains #######

#ARM_TOOCHAIN	?= /opt/gcc-arm/gcc-arm-11.2-2022.02-x86_64-arm-none-eabi/bin
#ARM_TOOCHAIN	?= /opt/gcc-arm/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi/bin
ARM_TOOCHAIN	?= /opt/gcc-arm/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi/bin

# path to JLinkExe
JLINKEXE		?= /opt/SEGGER/JLink/JLinkExe
# path to PyOCD
PYOCD_EXE		?= pyocd

##### Paths ############

# C source folders
CDIRS	:= User 
# C source files (if there are any single ones)
CFILES := 

# ASM source folders
ADIRS	:= User
# ASM single files
AFILES	:= 

# Include paths
INCLUDES	:= Libraries/CMSIS/Core/Include \
			Libraries/CMSIS/Device/PUYA/PY32F4xx/Include \
			User

##### Library Paths ############

# Library flags
LIB_FLAGS		= $(MCU_TYPE)
# JLink device (Uppercases)
JLINK_DEVICE	?= $(shell echo $(MCU_TYPE) | tr '[:lower:]' '[:upper:]')
# PyOCD device (Lowercases)
PYOCD_DEVICE	?= $(shell echo $(MCU_TYPE) | tr '[:upper:]' '[:lower:]')
# Link descript file: 
LDSCRIPT		= Libraries/LDScripts/$(PYOCD_DEVICE).ld


CDIRS		+= Libraries/PY32F4xx_HAL_Driver/Src 
INCLUDES	+= Libraries/PY32F4xx_HAL_Driver/Inc
LIB_FLAGS   += USE_HAL_DRIVER
# Startup file
AFILES		:= Libraries/CMSIS/Device/PUYA/PY32F4xx/Source/Templates/gcc/startup_py32f403xx.s


######## Additional Libs ########



include ./rules.mk
