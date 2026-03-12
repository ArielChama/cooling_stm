################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/UserCode/Src/MainController.c \
../Core/UserCode/Src/bno055.c \
../Core/UserCode/Src/bnoController.c \
../Core/UserCode/Src/mathUtils.c \
../Core/UserCode/Src/vdcu_can.c 

OBJS += \
./Core/UserCode/Src/MainController.o \
./Core/UserCode/Src/bno055.o \
./Core/UserCode/Src/bnoController.o \
./Core/UserCode/Src/mathUtils.o \
./Core/UserCode/Src/vdcu_can.o 

C_DEPS += \
./Core/UserCode/Src/MainController.d \
./Core/UserCode/Src/bno055.d \
./Core/UserCode/Src/bnoController.d \
./Core/UserCode/Src/mathUtils.d \
./Core/UserCode/Src/vdcu_can.d 


# Each subdirectory must supply rules for building sources it contributes
Core/UserCode/Src/%.o Core/UserCode/Src/%.su Core/UserCode/Src/%.cyclo: ../Core/UserCode/Src/%.c Core/UserCode/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H7B0xx -c -I../Core/Inc -I"/home/mr-chama/STM32CubeIDE/workspace_2.0.0/cooling_stm/Core/UserCode/Inc" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"/home/mr-chama/STM32CubeIDE/workspace_2.0.0/cooling_stm/Core/UserCode" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-UserCode-2f-Src

clean-Core-2f-UserCode-2f-Src:
	-$(RM) ./Core/UserCode/Src/MainController.cyclo ./Core/UserCode/Src/MainController.d ./Core/UserCode/Src/MainController.o ./Core/UserCode/Src/MainController.su ./Core/UserCode/Src/bno055.cyclo ./Core/UserCode/Src/bno055.d ./Core/UserCode/Src/bno055.o ./Core/UserCode/Src/bno055.su ./Core/UserCode/Src/bnoController.cyclo ./Core/UserCode/Src/bnoController.d ./Core/UserCode/Src/bnoController.o ./Core/UserCode/Src/bnoController.su ./Core/UserCode/Src/mathUtils.cyclo ./Core/UserCode/Src/mathUtils.d ./Core/UserCode/Src/mathUtils.o ./Core/UserCode/Src/mathUtils.su ./Core/UserCode/Src/vdcu_can.cyclo ./Core/UserCode/Src/vdcu_can.d ./Core/UserCode/Src/vdcu_can.o ./Core/UserCode/Src/vdcu_can.su

.PHONY: clean-Core-2f-UserCode-2f-Src

