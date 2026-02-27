/*
 * vdcu_can.h
 *
 *  Created on: 10/02/2026
 *      Author: mr-chama
 */

#ifndef USERCODE_INC_VDCU_CAN_H_
#define USERCODE_INC_VDCU_CAN_H_
#include <stdint.h>
#include "stm32h7xx_hal.h"

typedef union {
  uint64_t value;
  struct {
    int16_t s0;
    int16_t s1;
    int16_t s2;
    int16_t s3;
  };
  uint8_t byte[8];
} BytesUnion;

void VDCU_CAN_SendTemp(int16_t temp[]);

void VDCU_CAN_SendPosition(float x, float y, float z);

extern FDCAN_HandleTypeDef hfdcan1;

#endif /* USERCODE_INC_VDCU_CAN_H_ */
