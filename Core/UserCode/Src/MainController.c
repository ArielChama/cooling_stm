#include "MainController.h"
#include "mathUtils.h"

#define NUM_NTCS 2

uint32_t temp_value_NTC_BIN[NUM_NTCS];
float temp_value_NTC[NUM_NTCS];

const float SERIES_RESISTOR = 10000.0; // Resistor fixo que usaste no divisor de tensão
const float BETA = 3950.0;             // Valor típico para NTC 10k (ajusta se necessário)
const float TEMP_NOMINAL = 25.0;       // Temp de referência da tabela
const float RESISTOR_NOMINAL = 10000.0;// Resistência aos 25°C


float getCelsius(int rawAdc) {
  if (rawAdc == 0) return -273.15; // Evita divisão por zero

  // 1. Calcular resistência do NTC (Assume-se divisor de tensão com 10k ligado ao VCC)
  float resistencia = SERIES_RESISTOR / (1023.0 / (float)rawAdc - 1.0);

  float temp = linear_interpolation(ntc_res_ohm, ntc_temp_c, 29, resistencia, false);

  return temp;
}


void MainController_Init(void) {
    // Inicializa todos os subsistemas de software

    // NTCManager_Init();

	HAL_ADC_Start_DMA(&hadc1, temp_value_NTC_BIN, NUM_NTCS);

	HAL_TIM_Base_Start(&htim6);

	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_2);
}

void MainController_Run(void) {
	for (int i = 0; i < NUM_NTCS; i++) {
		temp_value_NTC[i] = getCelsius(temp_value_NTC_BIN[i]);

		if (temp_value_NTC[i] >= VALUE_MAX_TEMP) {
			htim5.Instance->CCR1 = 0.85 * TIM5_ARR;
			htim5.Instance->CCR2 = 0.85 * TIM5_ARR;
		} else {
			htim5.Instance->CCR1 = 0.25 * TIM5_ARR;
			htim5.Instance->CCR2 = 0.25 * TIM5_ARR;
		}
	}

	VDCU_CAN_SendTemp(temp_value_NTC);
}
