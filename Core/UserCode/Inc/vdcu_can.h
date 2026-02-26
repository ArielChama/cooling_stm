/*
 * vdcu_can.h
 *
 *  Created on: 10/02/2026
 *      Author: mr-chama
 */

#ifndef USERCODE_INC_VDCU_CAN_H_
#define USERCODE_INC_VDCU_CAN_H_

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

void VDCU_CAN_SendTemp(int16_t torque, bool enable);


#endif /* USERCODE_INC_VDCU_CAN_H_ */
