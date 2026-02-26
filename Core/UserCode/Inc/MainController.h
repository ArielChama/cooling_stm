#ifndef __MAIN_CONTROLLER_H
#define __MAIN_CONTROLLER_H

#include "stm32h7xx_hal.h"

#define VALUE_EACH_STEP 3.3 / 4096 // 4096 is 12^12
#define VALUE_MAX_TEMP 50
#define TIM5_ARR 11199

// Temperatura em graus Celsius
const int ntc_temp_c[] = {
    -40, -35, -30, -25, -20, -15, -10, -5,
      0,   5,  10,  15,  20,  25,  30,  35,
     40,  45,  50,  55,  60,  65,  70,  75,
     80,  85,  90,  95, 100
};

// Resistência do NTC em ohms
const int ntc_res_ohm[] = {
    94331, 68175, 49796, 36743, 27377, 20590, 15626, 11960,
     9231,  7180,  5628,  4444,  3533,  2828,  2278,  1847,
     1506,  1235,  1018,   844,   703,   589,   495,   418,
      355,   303,   259,   222,   192
};


extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim5;

// Funções que serão chamadas pelo main.c gerado
float getCelsius(int rawAdc);
void MainController_Init(void);
void MainController_Run(void);

#endif
