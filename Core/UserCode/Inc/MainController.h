#ifndef __MAIN_CONTROLLER_H
#define __MAIN_CONTROLLER_H

#include "stm32h7xx_hal.h"

#define VALUE_EACH_STEP 3.3 / 4096 // 4096 is 12^12
#define VALUE_MAX_TEMP 50
#define TIM5_ARR 11199
#define TIM2_ARR 61399



extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim5;

// Funções que serão chamadas pelo main.c gerado
float getCelsius(int rawAdc);
void MainController_Init(void);
void MainController_Run(void);

#endif
